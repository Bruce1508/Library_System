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
        
        library[10].id = 1011; 
        strcpy(library[10].title, "Educated"); 
        strcpy(library[10].author, "Tara Westover"); 
        strcpy(library[10].category, "Memoir"); 
        library[10].publication_year = 2018; 
        library[10].price = 17.99; 
        library[10].quantity = 5; 
        library[10].borrowed = 2;
        
        library[11].id = 1012; 
        strcpy(library[11].title, "The Alchemist"); 
        strcpy(library[11].author, "Paulo Coelho"); 
        strcpy(library[11].category, "Fiction"); 
        library[11].publication_year = 1988; 
        library[11].price = 11.99; 
        library[11].quantity = 6; 
        library[11].borrowed = 3;
        
        library[12].id = 1013; 
        strcpy(library[12].title, "Sapiens: A Brief History of Humankind"); 
        strcpy(library[12].author, "Yuval Noah Harari"); 
        strcpy(library[12].category, "History"); 
        library[12].publication_year = 2014; 
        library[12].price = 21.99; 
        library[12].quantity = 4; 
        library[12].borrowed = 1;
        
        library[13].id = 1014; 
        strcpy(library[13].title, "The Great Gatsby"); 
        strcpy(library[13].author, "F. Scott Fitzgerald"); 
        strcpy(library[13].category, "Classic Literature"); 
        library[13].publication_year = 1925; 
        library[13].price = 9.99; 
        library[13].quantity = 7; 
        library[13].borrowed = 2;
        
        library[14].id = 1015; 
        strcpy(library[14].title, "The Art of War"); 
        strcpy(library[14].author, "Sun Tzu"); 
        strcpy(library[14].category, "Philosophy"); 
        library[14].publication_year = 500; 
        library[14].price = 8.99; 
        library[14].quantity = 5; 
        library[14].borrowed = 1;
        
        library[15].id = 1016; 
        strcpy(library[15].title, "Brave New World"); 
        strcpy(library[15].author, "Aldous Huxley"); 
        strcpy(library[15].category, "Dystopian Fiction"); 
        library[15].publication_year = 1932; 
        library[15].price = 12.50; 
        library[15].quantity = 4; 
        library[15].borrowed = 2;
        
        library[16].id = 1017; 
        strcpy(library[16].title, "The Power of Habit"); 
        strcpy(library[16].author, "Charles Duhigg"); 
        strcpy(library[16].category, "Psychology"); 
        library[16].publication_year = 2012; 
        library[16].price = 16.99; 
        library[16].quantity = 6; 
        library[16].borrowed = 3;
        
        library[17].id = 1018; 
        strcpy(library[17].title, "The Road"); 
        strcpy(library[17].author, "Cormac McCarthy"); 
        strcpy(library[17].category, "Post-Apocalyptic"); 
        library[17].publication_year = 2006; 
        library[17].price = 14.95; 
        library[17].quantity = 3; 
        library[17].borrowed = 1;
        
        library[18].id = 1019; 
        strcpy(library[18].title, "Harry Potter and the Philosopher's Stone"); 
        strcpy(library[18].author, "J.K. Rowling"); 
        strcpy(library[18].category, "Young Adult Fantasy"); 
        library[18].publication_year = 1997; 
        library[18].price = 13.99; 
        library[18].quantity = 10; 
        library[18].borrowed = 6;
        
        library[19].id = 1020; 
        strcpy(library[19].title, "The Hunger Games"); 
        strcpy(library[19].author, "Suzanne Collins"); 
        strcpy(library[19].category, "Young Adult Dystopian"); 
        library[19].publication_year = 2008; 
        library[19].price = 12.99; 
        library[19].quantity = 8; 
        library[19].borrowed = 5;
        
        library[20].id = 1021; 
        strcpy(library[20].title, "Becoming"); 
        strcpy(library[20].author, "Michelle Obama"); 
        strcpy(library[20].category, "Autobiography"); 
        library[20].publication_year = 2018; 
        library[20].price = 19.99; 
        library[20].quantity = 7; 
        library[20].borrowed = 4;
        
        library[21].id = 1022; 
        strcpy(library[21].title, "The Da Vinci Code"); 
        strcpy(library[21].author, "Dan Brown"); 
        strcpy(library[21].category, "Thriller"); 
        library[21].publication_year = 2003; 
        library[21].price = 13.95; 
        library[21].quantity = 5; 
        library[21].borrowed = 2;
        
        library[22].id = 1023; 
        strcpy(library[22].title, "Principles of Computer Science"); 
        strcpy(library[22].author, "David Eck"); 
        strcpy(library[22].category, "Computer Science"); 
        library[22].publication_year = 2016; 
        library[22].price = 34.99; 
        library[22].quantity = 6; 
        library[22].borrowed = 3;
        
        library[23].id = 1024; 
        strcpy(library[23].title, "Midnight's Children"); 
        strcpy(library[23].author, "Salman Rushdie"); 
        strcpy(library[23].category, "Magical Realism"); 
        library[23].publication_year = 1981; 
        library[23].price = 15.99; 
        library[23].quantity = 4; 
        library[23].borrowed = 1;
        
        library[24].id = 1025; 
        strcpy(library[24].title, "The Joy of Cooking"); 
        strcpy(library[24].author, "Irma S. Rombauer"); 
        strcpy(library[24].category, "Cookbook"); 
        library[24].publication_year = 1931; 
        library[24].price = 24.95; 
        library[24].quantity = 5; 
        library[24].borrowed = 2;
        
        library[25].id = 1026; 
        strcpy(library[25].title, "The Elements of Style"); 
        strcpy(library[25].author, "Strunk & White"); 
        strcpy(library[25].category, "Reference"); 
        library[25].publication_year = 1918; 
        library[25].price = 9.95; 
        library[25].quantity = 4; 
        library[25].borrowed = 0;
        
        library[26].id = 1027; 
        strcpy(library[26].title, "The Lord of the Rings"); 
        strcpy(library[26].author, "J.R.R. Tolkien"); 
        strcpy(library[26].category, "Fantasy"); 
        library[26].publication_year = 1954; 
        library[26].price = 29.99; 
        library[26].quantity = 8; 
        library[26].borrowed = 4;
        
        library[27].id = 1028; 
        strcpy(library[27].title, "When Breath Becomes Air"); 
        strcpy(library[27].author, "Paul Kalanithi"); 
        strcpy(library[27].category, "Medical Memoir"); 
        library[27].publication_year = 2016; 
        library[27].price = 14.99; 
        library[27].quantity = 5; 
        library[27].borrowed = 2;
        
        library[28].id = 1029; 
        strcpy(library[28].title, "The Little Prince"); 
        strcpy(library[28].author, "Antoine de Saint-Exupery"); 
        strcpy(library[28].category, "Children's Literature"); 
        library[28].publication_year = 1943; 
        library[28].price = 8.99; 
        library[28].quantity = 7; 
        library[28].borrowed = 3;
        
        library[29].id = 1030; 
        strcpy(library[29].title, "Economics: Principles and Policy"); 
        strcpy(library[29].author, "William J. Baumol"); 
        strcpy(library[29].category, "Economics"); 
        library[29].publication_year = 2011; 
        library[29].price = 42.99; 
        library[29].quantity = 4; 
        library[29].borrowed = 1;
        
        book_count = 30;
        
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
