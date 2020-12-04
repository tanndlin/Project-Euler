#include <stdio.h>

int daysInMonth(int month, int year) {

    switch (month) {
    case 1:
        return 31;
    case 2:
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 29;
            return 28;
        }

        if (year % 4 == 0)
            return 29;

        return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }
}

int main() {

    int day = 1;
    int month = 1;
    int year = 1900;
    int dayOfWeek = 1;
    int sundays = 0;

    while (!(day == 31 && year == 2000 && month == 12)) {

        day++;
        dayOfWeek++;

        if (dayOfWeek > 6)
            dayOfWeek = 0;

        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
        }

        if (month > 12) {
            month = 1;
            year++;
            // printf("Year: %d\n", year);
        }

        if (dayOfWeek == 0 && day == 1) {
            if (year > 1900)
                sundays++;
            // printf("Found One! %2d %2d, %d: %d\n", month, day, year, dayOfWeek);
        }
    }

    printf("Number of Sundays on first of Month: %d\n", sundays);

    return 0;
}