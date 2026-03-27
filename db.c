#include "db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static sqlite3 *db = NULL;

int db_open(const char *filename) {
    return sqlite3_open(filename, &db);
}

void db_close(void) {
    if (db) {
        sqlite3_close(db);
        db = NULL;
    }
}

int db_init(void) {
    const char *users_sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE NOT NULL,"
        "password TEXT NOT NULL" // plaintext for demo only
        ");";

    const char *grades_sql =
        "CREATE TABLE IF NOT EXISTS grades ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "student_id TEXT NOT NULL,"
        "name TEXT NOT NULL,"
        "score REAL"
        ");";

    char *err = NULL;
    if (sqlite3_exec(db, users_sql, 0, 0, &err) != SQLITE_OK) {
        fprintf(stderr, "创建用户表失败: %s\n", err);
        sqlite3_free(err);
        return 1;
    }
    if (sqlite3_exec(db, grades_sql, 0, 0, &err) != SQLITE_OK) {
        fprintf(stderr, "创建成绩表失败: %s\n", err);
        sqlite3_free(err);
        return 1;
    }

    /* ensure there is at least one admin user */
    const char *init_user_sql =
        "INSERT OR IGNORE INTO users(username,password) VALUES('admin','admin');";
    sqlite3_exec(db, init_user_sql, 0, 0, &err);
    if (err) sqlite3_free(err);

    return 0;
}

static int add_grade(const char *student_id, const char *name, double score) {
    const char *sql = "INSERT INTO grades(student_id,name,score) VALUES(?,?,?);";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) return 1;
    sqlite3_bind_text(stmt, 1, student_id, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, name, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 3, score);
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc == SQLITE_DONE ? 0 : 1;
}

void db_add_record_prompt(void) {
    char id[64], name[64];
    double score;
    printf("输入学号: ");
    scanf("%63s", id);
    printf("输入姓名: ");
    scanf("%63s", name);
    printf("输入成绩: ");
    scanf("%lf", &score);
    getchar();
    if (add_grade(id, name, score) == 0) {
        printf("添加成功。\n");
    } else {
        printf("添加失败。\n");
    }
}

void db_query_prompt(void) {
    char id[64];
    printf("查询学号: ");
    scanf("%63s", id);
    getchar();
    const char *sql = "SELECT student_id,name,score FROM grades WHERE student_id = ?;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        printf("查询失败。\n");
        return;
    }
    sqlite3_bind_text(stmt, 1, id, -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("学号: %s\n", sqlite3_column_text(stmt, 0));
        printf("姓名: %s\n", sqlite3_column_text(stmt, 1));
        printf("成绩: %.2f\n", sqlite3_column_double(stmt, 2));
    } else {
        printf("未找到记录。\n");
    }
    sqlite3_finalize(stmt);
}

void db_update_prompt(void) {
    char id[64];
    double score;
    printf("修改的学号: ");
    scanf("%63s", id);
    printf("新成绩: ");
    scanf("%lf", &score);
    getchar();
    const char *sql = "UPDATE grades SET score = ? WHERE student_id = ?;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        printf("准备更新失败。\n");
        return;
    }
    sqlite3_bind_double(stmt, 1, score);
    sqlite3_bind_text(stmt, 2, id, -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) == SQLITE_DONE) {
        printf("更新成功。\n");
    } else {
        printf("更新失败。\n");
    }
    sqlite3_finalize(stmt);
}

void db_delete_prompt(void) {
    char id[64];
    printf("删除的学号: ");
    scanf("%63s", id);
    getchar();
    const char *sql = "DELETE FROM grades WHERE student_id = ?;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        printf("准备删除失败。\n");
        return;
    }
    sqlite3_bind_text(stmt, 1, id, -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) == SQLITE_DONE) {
        printf("删除成功。\n");
    } else {
        printf("删除失败。\n");
    }
    sqlite3_finalize(stmt);
}

int db_export_csv(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return 1;
    fprintf(fp, "student_id,name,score\n");
    const char *sql = "SELECT student_id,name,score FROM grades;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fclose(fp);
        return 1;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        fprintf(fp, "%s,%s,%.2f\n",
                sqlite3_column_text(stmt, 0),
                sqlite3_column_text(stmt, 1),
                sqlite3_column_double(stmt, 2));
    }
    sqlite3_finalize(stmt);
    fclose(fp);
    printf("导出到 %s 完成。\n", filename);
    return 0;
}
