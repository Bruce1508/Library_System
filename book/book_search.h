//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#ifndef BOOK_SEARCH_H
#define BOOK_SEARCH_H

#include "book.h"

// Search for books in the library
void searchBook(Book *library, int count);

// Helper function for case-insensitive substring search
char* my_strcasestr(const char* haystack, const char* needle);

#endif // BOOK_SEARCH_H
