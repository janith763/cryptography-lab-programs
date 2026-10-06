#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    scanf("%s", key);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
            text[i] = ((text[i] - 'A') +
                       (toupper(key[j % strlen(key)]) - 'A')) % 26 + 'A';
            j++;
        }
    }

    printf("Encrypted text: %s", text);

    return 0;
}
