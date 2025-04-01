//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "book_borrow.h"

void borrowReturnMenu(Book *library, int count) {
    if (!isLoggedIn(current_user_id)) {
        showMessage("You need to log in to perform this action.");
        return;
    }
    printf("\n+-------------------------------+\n");
    printf("|      BORROW / RETURN          |\n");
    printf("+-------------------------------+\n");
    delay(SHORT_DELAY);
    if (count == 0) {
        showMessage("Library is empty. No books available.");
        return;
    }
    printf("1. Borrow a book\n");
    printf("2. Return a book\n");
    printf("0. Back\n");
    printf("Enter your choice: ");
    int choice = getIntInput();
    int id, index = -1;
    switch (choice) {
        case 0:
            return;
        case 1:
            printf("\nBorrow a Book\n");
            printf("Enter book ID to borrow: ");
            id = getIntInput();
            for (int i = 0; i < count; i++) {
                if (library[i].id == id) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                showMessage("Book not found. Please check the ID and try again.");
                return;
            }
            if (library[index].borrowed >= library[index].quantity) {
                showMessage("Sorry, all copies of this book are currently borrowed.");
                return;
            }
            library[index].borrowed++;
            delay(MEDIUM_DELAY);
            showProgressBar("Processing borrow request", 50);
            printf("\nBook Details:\n");
            printf("Title: %s\nAuthor: %s\nCategory: %s\n", 
                   library[index].title, library[index].author, library[index].category);
            printf("Available: %d out of %d\n", 
                   library[index].quantity - library[index].borrowed, library[index].quantity);
            showMessage("Book borrowed successfully!");
            break;
        case 2:
            printf("\nReturn a Book\n");
            printf("Enter book ID to return: ");
            id = getIntInput();
            for (int i = 0; i < count; i++) {
                if (library[i].id == id) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                showMessage("Book not found. Please check the ID and try again.");
                return;
            }
            if (library[index].borrowed <= 0) {
                showMessage("Error: No copies of this book are currently borrowed.");
                return;
            }
            library[index].borrowed--;
            delay(MEDIUM_DELAY);
            showProgressBar("Processing return request", 50);
            printf("\nBook Details:\n");
            printf("Title: %s\nAuthor: %s\nCategory: %s\n", 
                   library[index].title, library[index].author, library[index].category);
            printf("Available: %d out of %d\n", 
                   library[index].quantity - library[index].borrowed, library[index].quantity);
            showMessage("Book returned successfully!");
            break;
        default:
            showMessage("Invalid choice!");
            break;
    }
}
