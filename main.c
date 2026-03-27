#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "user.h"

void show_menu() {
    printf("\n===== 成绩管理系统 =====\n");
    printf("1. 添加学生成绩\n");
    printf("2. 查询学生成绩\n");
    printf("3. 修改学生成绩\n");
    printf("4. 删除学生成绩\n");
    printf("5. 导出所有成绩到 CSV\n");
    printf("6. 退出\n");
    printf("请选择: ");
}

int main() {
    if (db_open("grades.db") != 0) {
        fprintf(stderr, "无法打开数据库\n");
        return 1;
    }

    if (db_init() != 0) {
        fprintf(stderr, "数据库初始化失败\n");
        db_close();
        return 1;
    }

    printf("欢迎使用成绩管理系统（C版本）\n");

    if (!login_prompt()) {
        printf("登录失败，程序退出\n");
        db_close();
        return 0;
    }

    int choice;
    while (1) {
        show_menu();
        if (scanf("%d", &choice) != 1) break;
        getchar(); // consume newline
        switch (choice) {
            case 1:
                db_add_record_prompt();
                break;
            case 2:
                db_query_prompt();
                break;
            case 3:
                db_update_prompt();
                break;
            case 4:
                db_delete_prompt();
                break;
            case 5:
                db_export_csv("export.csv");
                break;
            case 6:
                printf("退出系统\n");
                db_close();
                return 0;
            default:
                printf("无效选项\n");
        }
    }

    db_close();
    return 0;
}
