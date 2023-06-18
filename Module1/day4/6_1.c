#include <stdio.h>
#include <ctype.h>

void toggleCase(char* str) {
    if (str == NULL) {
        return; // Handle null pointer case
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char str[] = {'A', 'b', 'c', 'd', ' ', 'X', 'Y', 'Z', '\0'};

    printf("Before toggling: %s\n", str);

    toggleCase(str);

    printf("After toggling: %s\n", str);

    return 0;
}
