#include <stdio.h>

int main() {
    int hours, minutes, seconds;

    printf("Enter the duration:\n");
    printf("Hours: ");
    scanf("%d", &hours);
    printf("Minutes: ");
    scanf("%d", &minutes);
    printf("Seconds: ");
    scanf("%d", &seconds);

    int total_seconds = (hours * 3600) + (minutes * 60) + seconds;
    printf("Total seconds: %d\n", total_seconds);

    return 0;
}
