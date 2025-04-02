//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "user_file.h"

// Function to save users to file
void saveUsersToFile(User *users, int user_count) {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    
    // Write user count to the first line
    fprintf(file, "%d\n", user_count);
    
    // Write user data
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%d\n%s\n%s\n", users[i].id, users[i].name, users[i].password);
    }
    
    fclose(file);
}

// Function to load users from file
void loadUsersFromFile(User *users, int *user_count) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        // File doesn't exist or can't be opened, start with 0 users
        *user_count = 0;
        return;
    }
    
    // Read user count
    fscanf(file, "%d\n", user_count);
    
    // Read user data
    for (int i = 0; i < *user_count; i++) {
        fscanf(file, "%d\n", &users[i].id);
        
        // Use fgets for strings to handle spaces
        fgets(users[i].name, sizeof(users[i].name), file);
        // Remove newline character
        users[i].name[strcspn(users[i].name, "\n")] = 0;
        
        fgets(users[i].password, sizeof(users[i].password), file);
        // Remove newline character
        users[i].password[strcspn(users[i].password, "\n")] = 0;
    }
    
    fclose(file);
    
    if (*user_count > 0) {
        showMessage("User data loaded successfully!");
    }
}

// Function to save last login user ID
void saveLastLoginUser(int user_id) {
    FILE *file = fopen("lastlogin.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to save login information.\n");
        return;
    }
    
    fprintf(file, "%d", user_id);
    fclose(file);
}

// Function to load last login user ID
void loadLastLoginUser(int *current_user_id) {
    FILE *file = fopen("lastlogin.txt", "r");
    if (file == NULL) {
        // No previous login info
        *current_user_id = -1;
        return;
    }
    
    int user_id;
    if (fscanf(file, "%d", &user_id) == 1) {
        // Check if the user ID exists in our users array
        for (int i = 0; i < user_count; i++) {
            if (users[i].id == user_id) {
                *current_user_id = user_id;
                showMessage("Auto login successful!");
                break;
            }
        }
    }
    
    fclose(file);
}
