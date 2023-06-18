#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isValidEmail(const char* email) {
    // Check for username, domain, and extension length
    int length = strlen(email);
    if (length == 0 || length > 255) {
        printf("Invalid: Length should be between 1 and 255 characters.\n");
        return false;
    }

    // Check for '@' symbol
    const char* atSymbol = strchr(email, '@');
    if (atSymbol == NULL) {
        printf("Invalid: Missing '@' symbol.\n");
        return false;
    }

    // Check for valid username
    int usernameLength = atSymbol - email;
    for (int i = 0; i < usernameLength; i++) {
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '_') {
            printf("Invalid: Username can only contain alphanumeric characters, dots, and underscores.\n");
            return false;
        }
    }

    // Check for valid domain and extension
    const char* domainExtension = atSymbol + 1;
    int domainExtensionLength = length - usernameLength - 1;
    if (domainExtensionLength == 0 || domainExtensionLength > 255) {
        printf("Invalid: Domain and extension should have a length between 1 and 255 characters.\n");
        return false;
    }

    for (int i = 0; i < domainExtensionLength; i++) {
        if (!isalnum(domainExtension[i]) && !islower(domainExtension[i]) && domainExtension[i] != '.') {
            printf("Invalid: Domain and extension can only contain alphanumeric characters, dots, and lowercase letters.\n");
            return false;
        }
    }

    return true;
}

int main() {
    // Test cases
    printf("%s\n", isValidEmail("hello@example.com") ? "Valid" : "Invalid");
    printf("%s\n", isValidEmail("hello@example.org") ? "Valid" : "Invalid");
    printf("%s\n", isValidEmail("mail2friend@hi5.com") ? "Valid" : "Invalid");
    printf("%s\n", isValidEmail("mail2admin@Prog.org") ? "Valid" : "Invalid");
    printf("%s\n", isValidEmail("guest_user@example.in") ? "Valid" : "Invalid");
    printf("%s\n", isValidEmail("guest.user@example.com") ? "Valid" : "Invalid");

    return 0;
}
