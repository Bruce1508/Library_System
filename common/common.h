//Nguyen Duc Anh Vo
//Mohammed Zakari
//Faizan Ahmed Osmani
//Assignment: 2
//Date: 17/03/2025

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Maximum number of books and users the library can hold
#define MAX_BOOKS 100
#define MAX_USERS 50
#define MAX_STRING_LENGTH 99

// Thời gian delay (tính bằng milliseconds)
#define SHORT_DELAY 800
#define MEDIUM_DELAY 1500
#define LONG_DELAY 3000

// Forward declarations of common utility functions
void showMessage(char* message);
void displayBarChart(char *label, int value, int maxValue);
void showProgressBar(char *operation, int sleep_time);
void delay(int milliseconds);
void clearInputBuffer();
int getIntInput();
float getFloatInput();
void getStringInput(char *buffer, int size);
int validateYear(int year);
int validateQuantity(int quantity);
float validatePrice(float price);

#endif // COMMON_H
