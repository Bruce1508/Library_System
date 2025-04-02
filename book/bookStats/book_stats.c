//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "book_stats.h"

void statisticsMenu(Book *library, int count) {
    if (!isLoggedIn(current_user_id)) {
        showMessage("You need to log in to perform this action.");
        return;
    }
    printf("\n+-------------------------------+\n");
    printf("|         STATISTICS            |\n");
    printf("+-------------------------------+\n");
    delay(SHORT_DELAY);
    if (count == 0) {
        showMessage("Library is empty. No statistics available.");
        return;
    }
    while (1) {
        printf("\nStatistics Options:\n");
        printf("1. Books by Category\n");
        printf("2. Books by Publication Year\n");
        printf("3. Most Popular Books (Most Borrowed)\n");
        printf("4. Most Available Books (Highest Quantity)\n");
        printf("5. Most Expensive Books\n");
        printf("6. Overall Statistics\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        int choice = getIntInput();
        if (choice == 0) {
            return;
        }
        switch (choice) {
            case 1: {
                printf("\nBooks by Category:\n");
                char categories[MAX_BOOKS][50];
                int category_counts[MAX_BOOKS] = {0};
                int unique_categories = 0;
                // Count books by category
                for (int i = 0; i < count; i++) {
                    int category_exists = 0;
                    for (int j = 0; j < unique_categories; j++) {
                        if (strcmp(library[i].category, categories[j]) == 0) {
                            category_counts[j]++;
                            category_exists = 1;
                            break;
                        }
                    }
                    if (!category_exists) {
                        strcpy(categories[unique_categories], library[i].category);
                        category_counts[unique_categories]++;
                        unique_categories++;
                    }
                }
                // Find maximum count for scaling bar chart
                int max_count = 0;
                for (int i = 0; i < unique_categories; i++) {
                    if (category_counts[i] > max_count) {
                        max_count = category_counts[i];
                    }
                }
                // Display bar chart
                printf("\nCategory Distribution:\n");
                for (int i = 0; i < unique_categories; i++) {
                    displayBarChart(categories[i], category_counts[i], max_count);
                }
                delay(MEDIUM_DELAY);
                break;
            }
            case 2: {
                printf("\nBooks by Publication Year:\n");
                int years[MAX_BOOKS];
                int year_counts[MAX_BOOKS] = {0};
                int unique_years = 0;
                // Count books by year
                for (int i = 0; i < count; i++) {
                    int year_exists = 0;
                    for (int j = 0; j < unique_years; j++) {
                        if (library[i].publication_year == years[j]) {
                            year_counts[j]++;
                            year_exists = 1;
                            break;
                        }
                    }
                    if (!year_exists) {
                        years[unique_years] = library[i].publication_year;
                        year_counts[unique_years]++;
                        unique_years++;
                    }
                }
                // Sort years
                for (int i = 0; i < unique_years - 1; i++) {
                    for (int j = 0; j < unique_years - i - 1; j++) {
                        if (years[j] > years[j + 1]) {
                            int temp_year = years[j];
                            years[j] = years[j + 1];
                            years[j + 1] = temp_year;
                            int temp_count = year_counts[j];
                            year_counts[j] = year_counts[j + 1];
                            year_counts[j + 1] = temp_count;
                        }
                    }
                }
                // Find maximum count for scaling bar chart
                int max_count = 0;
                for (int i = 0; i < unique_years; i++) {
                    if (year_counts[i] > max_count) {
                        max_count = year_counts[i];
                    }
                }
                // Display bar chart
                printf("\nPublication Year Distribution:\n");
                for (int i = 0; i < unique_years; i++) {
                    char year_str[10];
                    sprintf(year_str, "%d", years[i]);
                    displayBarChart(year_str, year_counts[i], max_count);
                }
                delay(MEDIUM_DELAY);
                break;
            }
            case 3: {
                printf("\nMost Popular Books (Most Borrowed):\n");
                // Create a copy of the library array for sorting
                Book temp_library[MAX_BOOKS];
                for (int i = 0; i < count; i++) {
                    temp_library[i] = library[i];
                }
                // Sort by borrowed count (descending)
                for (int i = 0; i < count - 1; i++) {
                    for (int j = 0; j < count - i - 1; j++) {
                        if (temp_library[j].borrowed < temp_library[j + 1].borrowed) {
                            Book temp = temp_library[j];
                            temp_library[j] = temp_library[j + 1];
                            temp_library[j + 1] = temp;
                        }
                    }
                }
                // Display top books
                printf("%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Borrowed");
                printf("---------------------------------------------------------------\n");
                int display_count = (count < 5) ? count : 5;
                for (int i = 0; i < display_count; i++) {
                    printf("%-5d %-30.30s %-20.20s %-10d\n", 
                           temp_library[i].id, temp_library[i].title, 
                           temp_library[i].author, temp_library[i].borrowed);
                }
                delay(MEDIUM_DELAY);
                break;
            }
            case 4: {
                printf("\nMost Available Books (Highest Quantity):\n");
                // Create a copy of the library array for sorting
                Book temp_library[MAX_BOOKS];
                for (int i = 0; i < count; i++) {
                    temp_library[i] = library[i];
                }
                // Sort by available quantity (descending)
                for (int i = 0; i < count - 1; i++) {
                    for (int j = 0; j < count - i - 1; j++) {
                        int avail_j = temp_library[j].quantity - temp_library[j].borrowed;
                        int avail_j1 = temp_library[j + 1].quantity - temp_library[j + 1].borrowed;
                        if (avail_j < avail_j1) {
                            Book temp = temp_library[j];
                            temp_library[j] = temp_library[j + 1];
                            temp_library[j + 1] = temp;
                        }
                    }
                }
                // Display top books
                printf("%-5s %-30s %-20s %-10s %-10s\n", "ID", "Title", "Author", "Available", "Total");
                printf("-----------------------------------------------------------------------\n");
                int display_count = (count < 5) ? count : 5;
                for (int i = 0; i < display_count; i++) {
                    int available = temp_library[i].quantity - temp_library[i].borrowed;
                    printf("%-5d %-30.30s %-20.20s %-10d %-10d\n", 
                           temp_library[i].id, temp_library[i].title, 
                           temp_library[i].author, available, temp_library[i].quantity);
                }
                delay(MEDIUM_DELAY);
                break;
            }
            case 5: {
                printf("\nMost Expensive Books:\n");
                // Create a copy of the library array for sorting
                Book temp_library[MAX_BOOKS];
                for (int i = 0; i < count; i++) {
                    temp_library[i] = library[i];
                }
                // Sort by price (descending)
                for (int i = 0; i < count - 1; i++) {
                    for (int j = 0; j < count - i - 1; j++) {
                        if (temp_library[j].price < temp_library[j + 1].price) {
                            Book temp = temp_library[j];
                            temp_library[j] = temp_library[j + 1];
                            temp_library[j + 1] = temp;
                        }
                    }
                }
                // Display top books
                printf("%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Price");
                printf("---------------------------------------------------------------\n");
                int display_count = (count < 5) ? count : 5;
                for (int i = 0; i < display_count; i++) {
                    printf("%-5d %-30.30s %-20.20s $%-9.2f\n", 
                           temp_library[i].id, temp_library[i].title, 
                           temp_library[i].author, temp_library[i].price);
                }
                delay(MEDIUM_DELAY);
                break;
            }
            case 6: {
                printf("\nOverall Statistics:\n");
                int total_books = count;
                int total_unique_titles = count;
                int total_quantity = 0;
                int total_borrowed = 0;
                float total_value = 0;
                
                for (int i = 0; i < count; i++) {
                    total_quantity += library[i].quantity;
                    total_borrowed += library[i].borrowed;
                    total_value += library[i].price * library[i].quantity;
                }
                printf("Total Books in System: %d unique titles\n", total_unique_titles);
                printf("Total Quantity: %d books\n", total_quantity);
                printf("Books Currently Borrowed: %d books\n", total_borrowed);
                printf("Available Books: %d books\n", total_quantity - total_borrowed);
                printf("Total Library Value: $%.2f\n", total_value);

                int max_val = (total_quantity > total_borrowed) ? total_quantity : total_borrowed;

                printf("\nInventory Status:\n");
                displayBarChart("Total", total_quantity, max_val);
                displayBarChart("Borrowed", total_borrowed, max_val);
                displayBarChart("Available", total_quantity - total_borrowed, max_val);
                delay(MEDIUM_DELAY);
                break;
            }
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}
