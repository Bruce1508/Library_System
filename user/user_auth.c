//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "user_auth.h"
#include "user_file.h"

void displayUserMenu() {
    printf("\n+-------------------------------+\n");
    printf("|       USER MANAGEMENT         |\n");
    printf("+-------------------------------+\n");
    printf("|  1. Register new user         |\n");
    printf("|  2. Login                     |\n");
    printf("|  0. Exit                      |\n");
    printf("+-------------------------------+\n");
}

int isLoggedIn(int current_user_id) {
    return current_user_id != -1;
}

void loginUser(User *users, int user_count, int *current_user_id) {
    if (isLoggedIn(*current_user_id)) {
        showMessage("You are already logged in.");
        return;
    }
    int id;
    char password[50];
    printf("Enter user ID: ");
    id = getIntInput();
    printf("Enter password: ");
    getStringInput(password, sizeof(password));
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == id && strcmp(users[i].password, password) == 0) {
            *current_user_id = id;
            
            // Save the login information to file
            saveLastLoginUser(id);
            
            showMessage("Login successful!");
            return;
        }
    }
    showMessage("Invalid user ID or password.");
}

void logoutUser(int *current_user_id) {
    if (!isLoggedIn(*current_user_id)) {
        showMessage("You are not logged in.");
        return;
    }
    *current_user_id = -1;
    
    // Delete the last login file
    remove("lastlogin.txt");
    
    showMessage("Logged out successfully!");
}
