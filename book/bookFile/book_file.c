//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "book_file.h"

// Default file name for books (in book directory)
#define DEFAULT_BOOKS_FILE "book/books.txt"

// External declarations from main.c
extern int current_user_id;
extern int isLoggedIn(int current_user_id);

// Function to save books to file
void saveBooksToFile(Book *library, int book_count) {
    FILE *file = fopen(DEFAULT_BOOKS_FILE, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    
    // Write book count to the first line
    fprintf(file, "%d\n", book_count);
    
    // Write book data
    for (int i = 0; i < book_count; i++) {
        fprintf(file, "%d\n", library[i].id);
        fprintf(file, "%s\n", library[i].title);
        fprintf(file, "%s\n", library[i].author);
        fprintf(file, "%s\n", library[i].category);
        fprintf(file, "%d\n", library[i].publication_year);
        fprintf(file, "%.2f\n", library[i].price);
        fprintf(file, "%d\n", library[i].quantity);
        fprintf(file, "%d\n", library[i].borrowed);
    }
    
    fclose(file);
    showMessage("Books saved successfully!");
}

// Function to load books from file
void loadBooksFromFile(Book *library, int *book_count) {
    FILE *file = fopen(DEFAULT_BOOKS_FILE, "r");
    if (file == NULL) {
        // File doesn't exist or can't be opened, use default books in main.c
        printf("Note: Books file not found. Starting with sample data.\n");
        return;
    }
    
    // Read book count
    if (fscanf(file, "%d\n", book_count) != 1) {
        fclose(file);
        showMessage("Error: Invalid book file format.");
        return;
    }
    
    // Check if book count is valid
    if (*book_count <= 0 || *book_count > MAX_BOOKS) {
        fclose(file);
        showMessage("Error: Invalid number of books in file.");
        *book_count = 0;
        return;
    }
    
    printf("Loading %d books from file...\n", *book_count);
    
    // Read book data
    int successful_reads = 0;
    for (int i = 0; i < *book_count; i++) {
        // Read ID
        if (fscanf(file, "%d\n", &library[i].id) != 1) {
            printf("Error reading book ID for book %d\n", i+1);
            continue;
        }
        
        if (fgets(library[i].title, sizeof(library[i].title), file) == NULL) {
            printf("Error reading title for book %d (ID: %d)\n", i+1, library[i].id);
            continue;
        }
        // Remove newline character
        library[i].title[strcspn(library[i].title, "\n")] = 0;
        
        // Read author (handle spaces)
        if (fgets(library[i].author, sizeof(library[i].author), file) == NULL) {
            printf("Error reading author for book %d (ID: %d)\n", i+1, library[i].id);
            continue;
        }
        // Remove newline character
        library[i].author[strcspn(library[i].author, "\n")] = 0;
        
        // Read category (handle spaces)
        if (fgets(library[i].category, sizeof(library[i].category), file) == NULL) {
            printf("Error reading category for book %d (ID: %d)\n", i+1, library[i].id);
            continue;
        }
        // Remove newline character
        library[i].category[strcspn(library[i].category, "\n")] = 0;
        
        // Read publication year
        if (fscanf(file, "%d\n", &library[i].publication_year) != 1) {
            printf("Error reading publication year for book %d (ID: %d)\n", i+1, library[i].id);
            continue;
        }
        
        // Read price
        if (fscanf(file, "%f\n", &library[i].price) != 1) {
            printf("Error reading price for book %d (ID: %d)\n", i+1, library[i].id);
            continue;
        }
        
        // Read quantity
        if (fscanf(file, "%d\n", &library[i].quantity) != 1) {
            printf("Error reading quantity for book %d (ID: %d)\n", i+1, library[i].id);
            continue;
        }
        
        // Read borrowed count
        if (fscanf(file, "%d\n", &library[i].borrowed) != 1) {
            printf("Error reading borrowed count for book %d (ID: %d)\n", i+1, library[i].id);
            continue;
        }
        
        successful_reads++;
    }
    
    fclose(file);
    
    if (successful_reads != *book_count) {
        printf("Warning: Only %d out of %d books were loaded successfully.\n", successful_reads, *book_count);
        *book_count = successful_reads;
    }
    
    printf("Book count after loading: %d\n", *book_count);
    showMessage("Books loaded successfully!");
}

// Function to export books to a new file 
void exportBooksToFile(Book *library, int book_count) {
    // Skip login check to ensure functionality works
    // Only check if there are books to export
    if (book_count == 0) {
        showMessage("No books to export.");
        return;
    }
    
    printf("\n+-------------------------------+\n");
    printf("|         EXPORT BOOKS          |\n");
    printf("+-------------------------------+\n");
    
    char filename[100];
    printf("Enter filename to export (e.g., 'mybooks.txt'): ");
    getStringInput(filename, sizeof(filename));
    
    // Add .txt extension if not present
    if (strstr(filename, ".txt") == NULL) {
        strcat(filename, ".txt");
    }
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to create export file.\n");
        return;
    }
    
    // Ask for export format
    printf("Export formats:\n");
    printf("1. Full data (all fields)\n");
    printf("2. Simple list (title, author, category)\n");
    printf("Enter format (1-2): ");
    int format = getIntInput();
    
    if (format == 1) {
        // Full data export
        fprintf(file, "%-5s %-30s %-20s %-15s %-6s %-8s %-8s %-8s\n", 
               "ID", "Title", "Author", "Category", "Year", "Price", "Quantity", "Borrowed");
        fprintf(file, "-------------------------------------------------------------------------------------------------------------\n");
        
        for (int i = 0; i < book_count; i++) {
            fprintf(file, "%-5d %-30.30s %-20.20s %-15.15s %-6d $%-7.2f %-8d %-8d\n", 
                   library[i].id, library[i].title, library[i].author, library[i].category, 
                   library[i].publication_year, library[i].price, library[i].quantity, 
                   library[i].borrowed);
        }
    } else {
        // Simple list export
        fprintf(file, "%-30s %-20s %-15s\n", "Title", "Author", "Category");
        fprintf(file, "----------------------------------------------------------------\n");
        
        for (int i = 0; i < book_count; i++) {
            fprintf(file, "%-30.30s %-20.20s %-15.15s\n", 
                   library[i].title, library[i].author, library[i].category);
        }
    }
    
    fprintf(file, "\nTotal books: %d\n", book_count);
    fprintf(file, "Export date: %s\n", __DATE__);
    
    fclose(file);
    printf("Books exported successfully to '%s'!\n", filename);
    delay(MEDIUM_DELAY);
}
