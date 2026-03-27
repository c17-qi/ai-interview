#include "user.h"
#include "db.h"
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

bool login_prompt(void) {
    char username[64];
    char password[64];
    printf("用户名: ");
    if (scanf("%63s", username) != 1) return false;
    printf("密码: ");
    if (scanf("%63s", password) != 1) return false;
    getchar();

    const char *sql = "SELECT COUNT(*) FROM users WHERE username = ? AND password = ?;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        return false;
    }
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);
    bool success = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        success = (count > 0);
    }
    sqlite3_finalize(stmt);
    return success;
}
