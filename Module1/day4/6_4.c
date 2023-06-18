#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getMonthDays(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int countDays(int day, int month, int year) {
    int totalDays = 0;

    // Calculate days for previous years
    for (int y = 1; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    // Calculate days for previous months in the given year
    for (int m = 1; m < month; m++) {
        totalDays += getMonthDays(m, year);
    }

    // Add days for the given month
    totalDays += day;

    return totalDays;
}

int main() {
    char date[11];

    printf("Enter the date in DD/MM/YYYY format: ");
    scanf("%s", date);

    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    int totalDays = countDays(day, month, year);
    printf("Total number of days: %d\n", totalDays);

    return 0;
}
