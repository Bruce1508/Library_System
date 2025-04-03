//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#ifndef BOOK_FILE_H
#define BOOK_FILE_H

#include "../../common/common.h"
#include "../book.h"

// Function to save books to file
void saveBooksToFile(Book *library, int book_count);

// Function to load books from file
void loadBooksFromFile(Book *library, int *book_count);

// Function to export books to a new file 
void exportBooksToFile(Book *library, int book_count);

#endif 
