//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "book_display.h"

void displayAllBooks(Book *library, int count) {
    printf("\n+-------------------------------+\n");
    printf("|         ALL BOOKS             |\n");
    printf("+-------------------------------+\n");
    delay(SHORT_DELAY);
    if (count == 0) {
        showMessage("Library is empty. No books to display.");
        return;
    }
    printf("%-5s %-25s %-20s %-15s %-6s %-8s %-8s %-8s\n", 
           "ID", "Title", "Author", "Category", "Year", "Price", "Quantity", "Borrowed");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-25.25s %-20.20s %-15.15s %-6d $%-7.2f %-8d %-8d\n", 
               library[i].id, library[i].title, library[i].author, library[i].category, 
               library[i].publication_year, library[i].price, library[i].quantity, 
               library[i].borrowed);
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("Total books: %d\n", count);
    delay(MEDIUM_DELAY);
}
