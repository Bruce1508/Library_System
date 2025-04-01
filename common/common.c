//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#include "common.h"

void delay(int milliseconds) {
    printf("Processing...");
    fflush(stdout);
    clock_t start_time = clock();
    while (clock() < start_time + (milliseconds * CLOCKS_PER_SEC / 1000));
    printf("\r                \r");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getIntInput() {
    int value;
    char buffer[50];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return -1;  //return -1 if fgets = Null
    if (sscanf(buffer, "%d", &value) != 1) return -1;
    return value;
}

float getFloatInput() {
    float value;
    char buffer[50];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return -1.0;
    if (sscanf(buffer, "%f", &value) != 1) return -1.0;
    return value;
}

void getStringInput(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') buffer[len-1] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

int validateYear(int year) {
    int current_year = 2025;
    return (year > 0 && year <= current_year);
}

int validateQuantity(int quantity) {
    return quantity >= 0;
}

float validatePrice(float price) {
    return price >= 0.0;
}

void showMessage(char* message) {
    printf("\n%s\n", message);
}

void displayBarChart(char *label, int value, int maxValue) {
    printf("%-15s | ", label);
    int barLength = (value * 20) / (maxValue > 0 ? maxValue : 1);
    for (int i = 0; i < barLength; i++) printf("#");
    printf(" %d\n", value);
}

void showProgressBar(char *operation, int sleep_time) {
    printf("%s: ", operation);
    for (int i = 0; i < 20; i++) {
        printf("#");
        fflush(stdout);
        clock_t start_time = clock();
        while (clock() < start_time + (sleep_time * CLOCKS_PER_SEC / 1000));
    }
    printf(" Complete!\n");
}
