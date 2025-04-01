//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "book_update.h"

void updateBook(Book *library, int count) {
    if (!isLoggedIn(current_user_id)) {
        showMessage("You need to log in to perform this action.");
        return;
    }
    int id, index = -1;
    printf("\n+-------------------------------+\n");
    printf("|         UPDATE BOOK           |\n");
    printf("+-------------------------------+\n");
    delay(SHORT_DELAY);
    if (count == 0) {
        showMessage("Library is empty. No books to update.");
        return;
    }
    while (1) {
        printf("Enter the ID of the book to update (0 to cancel): ");
        id = getIntInput();
        if (id == 0) {
            showMessage("Update canceled.");
            return;
        }
        if (id < 0) {
            printf("Error: Invalid ID. Please enter a positive number.\n");
            continue;
        }
        for (int i = 0; i < count; i++) {
            if (library[i].id == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            printf("Book with ID %d not found in the library. Try another ID.\n", id);
            continue;
        }
        break;
    }
    printf("\nCurrent book details:\n");
    printf("1. ID: %d\n2. Title: %s\n3. Author: %s\n4. Category: %s\n5. Year: %d\n6. Price: %.2f\n7. Quantity: %d\n8. Borrowed: %d\n",
           library[index].id, library[index].title, library[index].author,
           library[index].category, library[index].publication_year,
           library[index].price, library[index].quantity, library[index].borrowed);
    printf("\nSelect field to update (1-7, 0 to finish): ");
    int field;
    while ((field = getIntInput()) != 0) {
        switch (field) {
            case 1:
                printf("Cannot update ID. Please choose another field.\n");
                break;
            case 2:
                printf("Enter new title: ");
                getStringInput(library[index].title, sizeof(library[index].title));
                printf("Title updated successfully.\n");
                break;
            case 3:
                printf("Enter new author: ");
                getStringInput(library[index].author, sizeof(library[index].author));
                printf("Author updated successfully.\n");
                break;
            case 4:
                printf("Enter new category: ");
                getStringInput(library[index].category, sizeof(library[index].category));
                printf("Category updated successfully.\n");
                break;
            case 5:
                printf("Enter new publication year: ");
                int year = getIntInput();
                if (validateYear(year)) {
                    library[index].publication_year = year;
                    printf("Publication year updated successfully.\n");
                } else {
                    printf("Error: Invalid publication year. Update canceled.\n");
                }
                break;
            case 6:
                printf("Enter new price: ");
                float price = getFloatInput();
                if (validatePrice(price)) {
                    library[index].price = price;
                    printf("Price updated successfully.\n");
                } else {
                    printf("Error: Invalid price. Update canceled.\n");
                }
                break;
            case 7:
                printf("Enter new quantity: ");
                int quantity = getIntInput();
                if (validateQuantity(quantity)) {
                    library[index].quantity = quantity;
                    printf("Quantity updated successfully.\n");
                } else {
                    printf("Error: Invalid quantity. Update canceled.\n");
                }
                break;
            case 8:
                printf("Enter new borrowed count: ");
                int borrowed = getIntInput();
                if (borrowed < 0) {
                    printf("Error: Borrowed count cannot be negative.\n");
                } else if (borrowed > library[index].quantity) {
                    printf("Error: Borrowed count cannot be greater than total quantity.\n");
                } else {
                    library[index].borrowed = borrowed;
                    printf("Borrowed count updated successfully.\n");
                }
                break;
            default:
                printf("Invalid field. Please try again.\n");
                break;
        }
        printf("\nSelect another field to update (1-7, 0 to finish): ");
    }
    showProgressBar("Updating book", 50);
    showMessage("Book updated successfully!");
}
