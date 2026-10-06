#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int a) {
    int x;
    for (x = 1; x < 26; x++)
        if ((a * x) % 26 == 1)
            return x;
    return -1;
}

int main() {
    char cipher[500];
    int a, b, inv, i;

    printf("Enter ciphertext: ");
    scanf(" %[^\n]", cipher);

    printf("\nAssumption: most frequent ciphertext B represents E\n");
    printf("and second most frequent ciphertext U represents T.\n");

    /* B = 1, U = 20, E = 4, T = 19
       1 = 4a + b (mod 26)
       20 = 19a + b (mod 26)
       Therefore a = 3 and b = 15. */

    a = 3;
    b = 15;
    inv = modInverse(a);

    printf("\nAffine key: a = %d, b = %d\n", a, b);
    printf("Decrypted text: ");

    for (i = 0; cipher[i] != '\0'; i++) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            int c = cipher[i] - 'A';
            int p = (inv * (c - b + 26)) % 26;
            printf("%c", p + 'A');
        } else if (cipher[i] >= 'a' && cipher[i] <= 'z') {
            int c = cipher[i] - 'a';
            int p = (inv * (c - b + 26)) % 26;
            printf("%c", p + 'a');
        } else {
            printf("%c", cipher[i]);
        }
    }

    printf("\n");
    return 0;
}
