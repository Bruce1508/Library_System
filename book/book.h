//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#ifndef BOOK_H
#define BOOK_H

#include "../common/common.h"

typedef struct {
    int id;
    char title[100];
    char author[100];
    char category[50];
    int publication_year;
    float price;
    int quantity;
    int borrowed;
} Book;

// Book management function prototypes
void displayMenu();
void addBook(Book *library, int *count);
void deleteBook(Book *library, int *count);
void updateBook(Book *library, int count);
void displayAllBooks(Book *library, int count);
void searchBook(Book *library, int count);
void statisticsMenu(Book *library, int count);
void borrowReturnMenu(Book *library, int count);

// Custom string function for case-insensitive substring search
char* my_strcasestr(const char* haystack, const char* needle);

// Reference to user authentication
extern int isLoggedIn(int current_user_id);

// Global variables declaration (defined in main.c)
extern Book library[];
extern int book_count;
extern int current_user_id;

#endif // BOOK_H
