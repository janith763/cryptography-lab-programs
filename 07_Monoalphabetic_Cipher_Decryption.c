#include <stdio.h>

int main() {
    char cipher[] =
        "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
        "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8"
        "¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485"
        "†528806*81(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    /* Frequency-analysis mapping for this classical substitution cipher. */
    const char symbols[] = "53‡†0)6*;4826.)8¶]:(?91—";
    const char letters[] = "AGODLSINTEHIVWRYFMCHU?"; /* mapping is handled below */

    int i;
    char ch;

    printf("Decrypted message:\n\n");

    for (i = 0; cipher[i] != '\0'; i++) {
        ch = cipher[i];

        switch (ch) {
            case '5': printf("A"); break;
            case '3': printf("G"); break;
            case '‡': printf("O"); break;
            case '†': printf("D"); break;
            case '0': printf("L"); break;
            case ')': printf("S"); break;
            case '6': printf("I"); break;
            case '*': printf("N"); break;
            case ';': printf("T"); break;
            case '4': printf("H"); break;
            case '2': printf("B"); break;
            case '.': printf("P"); break;
            case '(': printf("R"); break;
            case '?': printf("U"); break;
            case ':': printf("Y"); break;
            case '¶': printf("V"); break;
            case ']': printf("W"); break;
            case '1': printf("F"); break;
            case '9': printf("M"); break;
            case '8': printf("E"); break;
            case '—': printf("C"); break;
            default: printf("%c", ch); break;
        }
    }

    printf("\n");
    return 0;
}
