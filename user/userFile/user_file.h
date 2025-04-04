//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#ifndef USER_FILE_H
#define USER_FILE_H

#include "../user.h"

// User file operations function prototypes
void saveUsersToFile(User *users, int user_count);
void loadUsersFromFile(User *users, int *user_count);
void saveLastLoginUser(int user_id);
void loadLastLoginUser(int *current_user_id);

#endif // USER_FILE_H
