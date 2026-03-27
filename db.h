#ifndef DB_H
#define DB_H

#include <sqlite3.h>

int db_open(const char *filename);
int db_init(void);
void db_close(void);

/* CRUD helpers via prompts */
void db_add_record_prompt(void);
void db_query_prompt(void);
void db_update_prompt(void);
void db_delete_prompt(void);
int db_export_csv(const char *filename);

#endif // DB_H
