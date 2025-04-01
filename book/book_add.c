//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "book_add.h"

void addBook(Book *library, int *count) {
    if (!isLoggedIn(current_user_id)) {
        showMessage("You need to log in to perform this action.");
        return;
    }
    printf("\n+-------------------------------+\n");
    printf("|        ADD NEW BOOK            |\n");
    printf("+-------------------------------+\n");

    delay(SHORT_DELAY);
    if (*count >= MAX_BOOKS) {
        showMessage("Library is full. Cannot add more books.");
        return;
    }

    int newId, validId = 0;

    while (!validId) {
        printf("Enter book ID: ");
        newId = getIntInput();
        if (newId <= 0) {
            printf("Error: Invalid ID. Please enter a positive number.\n");
            continue;
        }

        int idExists = 0;
        for (int i = 0; i < *count; i++) {
            if (library[i].id == newId) {
                idExists = 1;
                break;
            }
        }
        if (idExists) {
            printf("Error: Book ID already exists. Please use a unique ID.\n");
            continue;
        }
        validId = 1;
    }

    library[*count].id = newId;
    int validTitle = 0;

    while (!validTitle) {
        printf("Enter book title: ");
        getStringInput(library[*count].title, sizeof(library[*count].title));
        if (strlen(library[*count].title) == 0) {
            printf("Error: Title cannot be empty. Please enter a valid title.\n");
            continue;
        }
        validTitle = 1;
    }

    int validAuthor = 0;
    while (!validAuthor) {
        printf("Enter author name: ");
        getStringInput(library[*count].author, sizeof(library[*count].author));
        if (strlen(library[*count].author) == 0) {
            printf("Error: Author name cannot be empty. Please enter a valid name.\n");
            continue;
        }
        validAuthor = 1;
    }

    int validCategory = 0;
    while (!validCategory) {
        printf("Enter category: ");
        getStringInput(library[*count].category, sizeof(library[*count].category));
        if (strlen(library[*count].category) == 0) {
            printf("Error: Category cannot be empty. Please enter a valid category.\n");
            continue;
        }
        validCategory = 1;
    }

    int validYear = 0;
    while (!validYear) {
        printf("Enter publication year: ");
        int year = getIntInput();
        if (!validateYear(year)) {
            printf("Error: Invalid publication year. Please enter a year between 1 and 2025.\n");
            continue;
        }
        library[*count].publication_year = year;
        validYear = 1;
    }

    int validPrice = 0;
    while (!validPrice) {
        printf("Enter price: ");
        float price = getFloatInput();
        if (!validatePrice(price)) {
            printf("Error: Invalid price. Price must be positive.\n");
            continue;
        }
        library[*count].price = price;
        validPrice = 1;
    }

    int validQuantity = 0;
    while (!validQuantity) {
        printf("Enter quantity: ");
        int quantity = getIntInput();
        if (!validateQuantity(quantity)) {
            printf("Error: Invalid quantity. Quantity must be positive.\n");
            continue;
        }
        library[*count].quantity = quantity;
        validQuantity = 1;
    }
    
    library[*count].borrowed = 0;
    delay(MEDIUM_DELAY);
    showProgressBar("Adding book", 50);
    showMessage("Book added successfully!");
    (*count)++;
}
