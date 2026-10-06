#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b, p, c;

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid value of a.\n");
        printf("a must be relatively prime to 26.\n");
        return 0;
    }

    printf("\nAllowed values of a: 1 3 5 7 9 11 15 17 19 21 23 25\n");
    printf("There is no limitation on b; b can be 0 to 25.\n");

    printf("\nEnter plaintext letter (A-Z): ");
    scanf(" %c", (char *)&p);
    p = p >= 'a' && p <= 'z' ? p - 'a' : p - 'A';

    c = (a * p + b) % 26;

    printf("Ciphertext letter: %c\n", c + 'A');

    return 0;
}
