//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#ifndef USER_AUTH_H
#define USER_AUTH_H

#include "../user.h"

// User authentication function prototypes
void displayUserMenu();
int isLoggedIn(int current_user_id);
void loginUser(User *users, int user_count, int *current_user_id);
void logoutUser(int *current_user_id);

#endif // USER_AUTH_H
