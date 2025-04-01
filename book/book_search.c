//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "book_search.h"

void searchBook(Book *library, int count) {
    if (!isLoggedIn(current_user_id)) {
        showMessage("You need to log in to perform this action.");
        return;
    }
    printf("\n+-------------------------------+\n");
    printf("|         SEARCH BOOKS          |\n");
    printf("+-------------------------------+\n");
    delay(SHORT_DELAY);
    if (count == 0) {
        showMessage("Library is empty. No books to search.");
        return;
    }
    printf("Search by:\n");
    printf("1. ID\n");
    printf("2. Title\n");
    printf("3. Author\n");
    printf("4. Category\n");
    printf("5. Year\n");
    printf("0. Back\n");
    printf("Enter your choice: ");
    int choice = getIntInput();
    int found = 0;
    char searchStr[100];
    int searchId, searchYear;
    Book results[MAX_BOOKS];
    int result_count = 0;
    switch (choice) {
        case 0:
            return;
        case 1:
            printf("Enter book ID to search: ");
            searchId = getIntInput();
            for (int i = 0; i < count; i++) {
                if (library[i].id == searchId) {
                    results[result_count++] = library[i];
                    found = 1;
                }
            }
            break;
        case 2:
            printf("Enter title to search (partial match is supported): ");
            getStringInput(searchStr, sizeof(searchStr));
            for (int i = 0; i < count; i++) {
                if (my_strcasestr(library[i].title, searchStr) != NULL) {
                    results[result_count++] = library[i];
                    found = 1;
                }
            }
            break;
        case 3:
            printf("Enter author to search (partial match is supported): ");
            getStringInput(searchStr, sizeof(searchStr));
            for (int i = 0; i < count; i++) {
                if (my_strcasestr(library[i].author, searchStr) != NULL) {
                    results[result_count++] = library[i];
                    found = 1;
                }
            }
            break;
        case 4:
            printf("Enter category to search (partial match is supported): ");
            getStringInput(searchStr, sizeof(searchStr));
            for (int i = 0; i < count; i++) {
                if (my_strcasestr(library[i].category, searchStr) != NULL) {
                    results[result_count++] = library[i];
                    found = 1;
                }
            }
            break;
        case 5:
            printf("Enter publication year to search: ");
            searchYear = getIntInput();
            for (int i = 0; i < count; i++) {
                if (library[i].publication_year == searchYear) {
                    results[result_count++] = library[i];
                    found = 1;
                }
            }
            break;
        default:
            showMessage("Invalid choice.");
            return;
    }
    if (!found) {
        showMessage("No matching books found.");
        return;
    }
    printf("\nSearch Results (%d books found):\n", result_count);
    printf("%-5s %-25s %-20s %-15s %-6s %-8s %-8s %-8s\n", 
           "ID", "Title", "Author", "Category", "Year", "Price", "Quantity", "Borrowed");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < result_count; i++) {
        printf("%-5d %-25.25s %-20.20s %-15.15s %-6d $%-7.2f %-8d %-8d\n", 
               results[i].id, results[i].title, results[i].author, results[i].category, 
               results[i].publication_year, results[i].price, results[i].quantity, 
               results[i].borrowed);
    }
    delay(MEDIUM_DELAY);
}

// Custom implementation of strcasestr since it's not available on Windows
char* my_strcasestr(const char* haystack, const char* needle) {
    char haystackCopy[256];
    char needleCopy[256];
    
    // Make copies of the strings
    strcpy(haystackCopy, haystack);
    strcpy(needleCopy, needle);
    
    // Convert both to lowercase
    for (int i = 0; haystackCopy[i]; i++) {
        haystackCopy[i] = tolower(haystackCopy[i]);
    }
    
    for (int i = 0; needleCopy[i]; i++) {
        needleCopy[i] = tolower(needleCopy[i]);
    }
    
    // Find the substring
    char* result = strstr(haystackCopy, needleCopy);
    
    // If found, return the corresponding position in the original string
    if (result) {
        int position = result - haystackCopy;
        return (char*)(haystack + position);
    }
    
    return NULL;
}
