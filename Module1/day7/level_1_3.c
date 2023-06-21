#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};

struct LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void readLog(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File '%s' not found.\n", fileName);
        return;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Skip header line

    while (fgets(line, sizeof(line), file)) {
        struct LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.time);
        logEntries[numEntries++] = entry;
    }

    fclose(file);
}

void displayLog() {
    for (int i = 0; i < numEntries; i++) {
        struct LogEntry entry = logEntries[i];
        printf("Entry No: %d\n", entry.entryNo);
        printf("Sensor No: %s\n", entry.sensorNo);
        printf("Temperature: %.1f\n", entry.temperature);
        printf("Humidity: %d\n", entry.humidity);
        printf("Light: %d\n", entry.light);
        printf("Time: %s\n", entry.time);
        printf("\n");
    }
}

int main() {
    const char *fileName = "data.csv";
    readLog(fileName);
    displayLog();
    return 0;
}
