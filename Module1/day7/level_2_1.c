#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    int entryNo;
    char sensorNo[3];
    float temperature;
    int humidity;
    int light;
};

int compare(const void *a, const void *b) {
    struct Data *dataA = (struct Data *)a;
    struct Data *dataB = (struct Data *)b;
    if (dataA->temperature < dataB->temperature)
        return 1;
    else if (dataA->temperature > dataB->temperature)
        return -1;
    else
        return 0;
}

int main() {
    FILE *file;
    struct Data data[100];
    int count = 0;

    // Open the file for reading
    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read the file line by line and store the data in the array of structures
    while (fscanf(file, "%d,%[^,],%f,%d,%d\n", &data[count].entryNo, data[count].sensorNo, &data[count].temperature, &data[count].humidity, &data[count].light) == 5) {
        count++;
    }

    // Close the file
    fclose(file);

    // Sort the array of structures based on the "Temperature" field in descending order
    qsort(data, count, sizeof(struct Data), compare);

    // Open the file for writing
    file = fopen("data_sorted.csv", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Write the sorted data to the new file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.1f,%d,%d\n", data[i].entryNo, data[i].sensorNo, data[i].temperature, data[i].humidity, data[i].light);
    }

    // Close the file
    fclose(file);

    printf("Sorting completed. Please check the 'data_sorted.csv' file.\n");

    return 0;
}
