#include <stdio.h>
#include <ctype.h>

char matrix[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

void findPosition(char ch, int *row, int *col) {
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

int main() {
    char text[] = "Must see you over Cadogan West. Coming at once.";
    char prepared[200];
    int n = 0, i, r1, c1, r2, c2;

    /* Remove spaces/punctuation and prepare Playfair pairs. */
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            if (ch == 'J')
                ch = 'I';

            if (n > 0 && prepared[n - 1] == ch) {
                prepared[n++] = 'X';
            }
            prepared[n++] = ch;
        }
    }

    if (n % 2 != 0)
        prepared[n++] = 'X';

    prepared[n] = '\0';

    printf("Plaintext pairs:\n");
    for (i = 0; i < n; i += 2)
        printf("%c%c ", prepared[i], prepared[i + 1]);

    printf("\n\nEncrypted text:\n");

    for (i = 0; i < n; i += 2) {
        findPosition(prepared[i], &r1, &c1);
        findPosition(prepared[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                   matrix[r1][(c1 + 1) % 5],
                   matrix[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            printf("%c%c",
                   matrix[(r1 + 1) % 5][c1],
                   matrix[(r2 + 1) % 5][c2]);
        } else {
            printf("%c%c",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}
