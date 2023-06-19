#include <stdio.h>
#include <string.h>

void rotate_string_left(char* str, int rotate_count) {
    int len = strlen(str);
    
    // Handle cases where rotation count exceeds string length
    rotate_count = rotate_count % len;
    
    // No need to rotate if rotation count is 0 or string length is 0
    if (rotate_count == 0 || len == 0) {
        return;
    }
    
    // Create a temporary buffer to store the rotated string
    char rotated[len + 1];
    
    // Copy the rotated part of the string
    strncpy(rotated, str + rotate_count, len - rotate_count);
    
    // Copy the remaining part of the string
    strncpy(rotated + len - rotate_count, str, rotate_count);
    
    // Null-terminate the rotated string
    rotated[len] = '\0';
    
    // Copy the rotated string back to the original string
    strcpy(str, rotated);
}

void rotate_string_right(char* str, int rotate_count) {
    int len = strlen(str);
    
    // Handle cases where rotation count exceeds string length
    rotate_count = rotate_count % len;
    
    // No need to rotate if rotation count is 0 or string length is 0
    if (rotate_count == 0 || len == 0) {
        return;
    }
    
    // Create a temporary buffer to store the rotated string
    char rotated[len + 1];
    
    // Copy the rotated part of the string
    strncpy(rotated + rotate_count, str, len - rotate_count);
    
    // Copy the remaining part of the string
    strncpy(rotated, str + len - rotate_count, rotate_count);
    
    // Null-terminate the rotated string
    rotated[len] = '\0';
    
    // Copy the rotated string back to the original string
    strcpy(str, rotated);
}

int main() {
    char string[] = "abcdxyz";
    int rotate_count_left = 2;
    int rotate_count_right = 3;
    
    printf("Original string: %s\n", string);
    
    // Perform left rotation
    rotate_string_left(string, rotate_count_left);
    printf("Left rotated string: %s\n", string);
    
    // Reset the string
    strcpy(string, "abcdxyz");
    
    // Perform right rotation
    rotate_string_right(string, rotate_count_right);
    printf("Right rotated string: %s\n", string);
    
    return 0;
}
