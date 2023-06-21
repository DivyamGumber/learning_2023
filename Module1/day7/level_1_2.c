#include <stdio.h>
#include <string.h>
#include <ctype.h>

void changeCase(char *str, char option) {
    int length = strlen(str);
    int i;

    switch (option) {
        case 'u':
            for (i = 0; i < length; i++) {
                str[i] = toupper(str[i]);
            }
            break;
        case 'l':
            for (i = 0; i < length; i++) {
                str[i] = tolower(str[i]);
            }
            break;
        case 's':
            str[0] = toupper(str[0]);
            for (i = 1; i < length; i++) {
                str[i] = tolower(str[i]);
            }
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./cp <option> <source file> <target file>\n");
        return 1;
    }

    char *option = argv[1];
    char *sourceFileName = argv[2];
    char *targetFileName = argv[3];

    FILE *sourceFile, *targetFile;
    char line[100];

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");

    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the target file in write mode
    targetFile = fopen(targetFileName, "w");

    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    while (fgets(line, sizeof(line), sourceFile)) {
        changeCase(line, option[0]);
        fputs(line, targetFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
