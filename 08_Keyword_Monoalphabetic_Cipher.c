#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char keyword[50], text[200], cipher[27];
    int used[26] = {0};
    int i, k = 0;

    printf("Enter keyword: ");
    scanf("%s", keyword);

    for (i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            cipher[k++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[i])
            cipher[k++] = 'A' + i;
    }

    cipher[26] = '\0';

    printf("Cipher alphabet: %s\n", cipher);

    getchar();
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Ciphertext: ");

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int index = toupper(text[i]) - 'A';
            printf("%c", cipher[index]);
        } else {
            printf("%c", text[i]);
        }
    }

    return 0;
}
