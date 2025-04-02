//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "user_register.h"
#include "user_file.h"

void registerUser(User *users, int *user_count) {
    if (*user_count >= MAX_USERS) {
        showMessage("User limit reached. Cannot register more users.");
        return;
    }

    int newId, validId = 0;

    while (!validId) {
        printf("Enter new user ID: ");
        newId = getIntInput();
        if (newId <= 0) {
            printf("Error: Invalid ID. Please enter a positive number.\n");
            continue;
        }
        int idExists = 0;
        for (int i = 0; i < *user_count; i++) {
            if (users[i].id == newId) {
                idExists = 1;
                break;
            }
        }
        if (idExists) {
            printf("Error: User ID already exists. Please use a unique ID.\n");
            continue;
        }
        validId = 1;
    }

    users[*user_count].id = newId;
    int validName = 0;

    while (!validName) {
        printf("Enter user name: ");
        getStringInput(users[*user_count].name, sizeof(users[*user_count].name));
        if (strlen(users[*user_count].name) == 0) {
            printf("Error: Name cannot be empty. Please enter a valid name.\n");
            continue;
        }
        validName = 1;
    }

    int validPassword = 0;

    while (!validPassword) {
        printf("Enter password: ");
        getStringInput(users[*user_count].password, sizeof(users[*user_count].password));
        if (strlen(users[*user_count].password) == 0) {
            printf("Error: Password cannot be empty. Please enter a valid password.\n");
            continue;
        }
        validPassword = 1;
    }
    
    delay(MEDIUM_DELAY);
    showProgressBar("Registering user", 50);
    showMessage("User registered successfully!");
    (*user_count)++;
    
    // Save users to file after registration
    saveUsersToFile(users, *user_count);
}
