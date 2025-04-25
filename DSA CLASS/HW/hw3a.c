#include <stdio.h>
#include <string.h>

// Function to compress a string by counting character frequencies
void compress(char *str, char *com) {
    int n = strlen(str);
    int count[128] = {0}; // Array to store the count of each character within the ASCII range
    int j = 0;

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        count[str[i]]++;
    }

    // Construct the compressed string
    for (int i = 0; i < 128; i++) {
        if (count[i] > 0) {
            com[j++] = (char)i;
            // Convert count to string and append it to com
            int num = count[i];
            char buffer[10];
            int k = 0;

            // Convert integer count to string
            while (num > 0) {
                buffer[k++] = '0' + (num % 10);
                num /= 10;
            }

            // Append the digits in reverse order to com
            for (int l = k - 1; l >= 0; l--) {
                com[j++] = buffer[l];
            }
        }
    }
    com[j] = '\0';
}

int main() {
    char str[100];
    char com[200]; // Ensure the compressed string has enough space

    printf("Enter a string: ");
    scanf("%s", str);

    compress(str, com);

    printf("Compressed string: %s\n", com);

    return 0;
}
