//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "book_delete.h"

void deleteBook(Book *library, int *count) {
    if (!isLoggedIn(current_user_id)) {
        showMessage("You need to log in to perform this action.");
        return;
    }
    int id, index = -1;
    printf("\n+-------------------------------+\n");
    printf("|          DELETE BOOK          |\n");
    printf("+-------------------------------+\n");
    delay(SHORT_DELAY);
    if (*count == 0) {
        showMessage("Library is empty. No books to delete.");
        return;
    }
    int validId = 0;
    while (!validId) {
        printf("Enter the ID of the book to delete: ");
        id = getIntInput();
        if (id <= 0) {
            printf("Error: Invalid ID. Please enter a positive number.\n");
            continue;
        }
        index = -1;
        for (int i = 0; i < *count; i++) {
            if (library[i].id == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            printf("Book with ID %d not found in the library. Try another ID.\n", id);
            continue;
        }
        validId = 1;
    }
    printf("\nBook details:\n");
    printf("ID: %d\nTitle: %s\nAuthor: %s\nCategory: %s\nYear: %d\nPrice: %.2f\nQuantity: %d\nBorrowed: %d\n", 
        library[index].id, library[index].title, library[index].author, 
        library[index].category, library[index].publication_year, 
        library[index].price, library[index].quantity, library[index].borrowed
    );
    printf("\nAre you sure you want to delete this book? (1 for Yes, 0 for No): ");
    int confirm = getIntInput();
    if (confirm != 1) {
        showMessage("Deletion canceled.");
        return;
    }
    for (int i = index; i < *count - 1; i++) {
        library[i] = library[i + 1];
    }
    (*count)--;
    delay(MEDIUM_DELAY);
    showProgressBar("Deleting book", 50);
    showMessage("Book deleted successfully!");
}
