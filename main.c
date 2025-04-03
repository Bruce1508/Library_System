//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "common/common.h"
#include "book/book.h"
#include "user/user.h"
#include "book/bookMenu/book_menu.h"
#include "book/bookAdd/book_add.h"
#include "book/bookDelete/book_delete.h"
#include "book/bookUpdate/book_update.h"
#include "book/bookDisplay/book_display.h"
#include "book/bookSearch/book_search.h"
#include "book/bookStats/book_stats.h"
#include "book/bookBorrow/book_borrow.h"
#include "user/userAuth/user_auth.h"
#include "user/userRegister/user_register.h"
#include "user/userFile/user_file.h"
#include "book/bookFile/book_file.h"

Book library[MAX_BOOKS];
User users[MAX_USERS];
int book_count = 0;
int user_count = 0;
int current_user_id = -1;

int main() {
    // Load books from file
    loadBooksFromFile(library, &book_count);
    
    // If no books were loaded, initialize with sample data
    if (book_count == 0) {
        library[0].id = 1001; 
        strcpy(library[0].title, "To Kill a Mockingbird"); 
        strcpy(library[0].author, "Harper Lee"); 
        strcpy(library[0].category, "Fiction"); 
        library[0].publication_year = 1960; 
        library[0].price = 12.99; 
        library[0].quantity = 5; 
        library[0].borrowed = 2;
        
        library[1].id = 1002; 
        strcpy(library[1].title, "Dune"); 
        strcpy(library[1].author, "Frank Herbert"); 
        strcpy(library[1].category, "Science Fiction"); 
        library[1].publication_year = 1965; 
        library[1].price = 14.50; 
        library[1].quantity = 3; 
        library[1].borrowed = 1;
        
        library[2].id = 1003;
        strcpy(library[2].title, "The Hobbit"); 
        strcpy(library[2].author, "J.R.R. Tolkien"); 
        strcpy(library[2].category, "Fantasy"); 
        library[2].publication_year = 1937; 
        library[2].price = 11.99; 
        library[2].quantity = 7; 
        library[2].borrowed = 3;
        
        library[3].id = 1004; 
        strcpy(library[3].title, "The Silent Patient"); 
        strcpy(library[3].author, "Alex Michaelides"); 
        strcpy(library[3].category, "Mystery"); 
        library[3].publication_year = 2019; 
        library[3].price = 16.99; 
        library[3].quantity = 4; 
        library[3].borrowed = 2;
        
        library[4].id = 1005; 
        strcpy(library[4].title, "Thinking, Fast and Slow"); 
        strcpy(library[4].author, "Daniel Kahneman"); 
        strcpy(library[4].category, "Non-fiction"); 
        library[4].publication_year = 2011; 
        library[4].price = 24.95; 
        library[4].quantity = 6; 
        library[4].borrowed = 4;
        
        library[5].id = 1006; 
        strcpy(library[5].title, "Steve Jobs"); 
        strcpy(library[5].author, "Walter Isaacson"); 
        strcpy(library[5].category, "Biography"); 
        library[5].publication_year = 2011; 
        library[5].price = 19.99; 
        library[5].quantity = 3; 
        library[5].borrowed = 1;
        
        library[6].id = 1007; 
        strcpy(library[6].title, "A Brief History of Time"); 
        strcpy(library[6].author, "Stephen Hawking"); 
        strcpy(library[6].category, "Science"); 
        library[6].publication_year = 1988; 
        library[6].price = 15.95; 
        library[6].quantity = 4; 
        library[6].borrowed = 0;
        
        library[7].id = 1008; 
        strcpy(library[7].title, "Guns, Germs, and Steel"); 
        strcpy(library[7].author, "Jared Diamond"); 
        strcpy(library[7].category, "History"); 
        library[7].publication_year = 1997; 
        library[7].price = 18.99; 
        library[7].quantity = 2; 
        library[7].borrowed = 0;
        
        library[8].id = 1009; 
        strcpy(library[8].title, "Clean Code"); 
        strcpy(library[8].author, "Robert C. Martin"); 
        strcpy(library[8].category, "Programming"); 
        library[8].publication_year = 2008; 
        library[8].price = 29.99; 
        library[8].quantity = 5; 
        library[8].borrowed = 3;
        
        library[9].id = 1010; 
        strcpy(library[9].title, "Atomic Habits"); 
        strcpy(library[9].author, "James Clear"); 
        strcpy(library[9].category, "Self-help"); 
        library[9].publication_year = 2018; 
        library[9].price = 13.50; 
        library[9].quantity = 8; 
        library[9].borrowed = 5;
        
        book_count = 10;
        
        // Save the initial books to file
        saveBooksToFile(library, book_count);
    }

    // Load saved users from file
    loadUsersFromFile(users, &user_count);
    
    // auto-login from saved credentials
    loadLastLoginUser(&current_user_id);

    printf("+----------------------------------+\n");
    printf("|     LIBRARY MANAGEMENT SYSTEM    |\n");
    printf("+----------------------------------+\n");
    showProgressBar("Initializing system", 50);
    showMessage("System ready!");
    delay(MEDIUM_DELAY);

    while (1) {
        if (!isLoggedIn(current_user_id)) {
            displayUserMenu();
            int choice;
            printf("Enter your choice: ");
            choice = getIntInput();
            switch (choice) {
                case 1:
                    registerUser(users, &user_count);
                    break;
                case 2:
                    loginUser(users, user_count, &current_user_id);
                    break;
                case 0:
                    showMessage("Exiting program...");
                    delay(LONG_DELAY);
                    return 0;
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
            }
        } else {
            displayMenu();
            int choice;
            printf("Enter your choice: ");
            choice = getIntInput();
            switch (choice) {
                case 1:
                    addBook(library, &book_count);
                    break;
                case 2:
                    deleteBook(library, &book_count);
                    break;
                case 3:
                    updateBook(library, book_count);
                    break;
                case 4:
                    displayAllBooks(library, book_count);
                    break;
                case 5:
                    searchBook(library, book_count);
                    break;
                case 6:
                    statisticsMenu(library, book_count);
                    break;
                case 7:
                    borrowReturnMenu(library, book_count);
                    break;
                case 8:
                    exportBooksToFile(library, book_count);
                    break;
                case 9:
                    // Save books before logout
                    saveBooksToFile(library, book_count);
                    logoutUser(&current_user_id);
                    break;
                case 0:
                    // Save books before exit
                    saveBooksToFile(library, book_count);
                    showMessage("Exiting program...");
                    delay(LONG_DELAY);
                    return 0;
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
            }
        }
        delay(MEDIUM_DELAY);
    }
    return 0;
}
