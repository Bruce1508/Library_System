//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#ifndef USER_H
#define USER_H

#include "../common/common.h"

typedef struct {
    int id;
    char name[100];
    char password[50];
} User;

// Forward declarations of all user-related functions
void displayUserMenu();
int isLoggedIn(int current_user_id);
void registerUser(User *users, int *user_count);
void loginUser(User *users, int user_count, int *current_user_id);
void logoutUser(int *current_user_id);
void saveUsersToFile(User *users, int user_count);
void loadUsersFromFile(User *users, int *user_count);
void saveLastLoginUser(int user_id);
void loadLastLoginUser(int *current_user_id);

// Global variables declaration (defined in main.c)
extern User users[];
extern int user_count;
extern int current_user_id;

#endif // USER_H
