#include <stdio.h>
int main(void){
 puts("ECB: a corrupted ciphertext block affects only its matching plaintext block.");
 puts("CBC: a bit error in transmitted C1 corrupts P1 and flips the matching bit in P2.");
 puts("CBC: blocks P3 onward are not affected by a bit error in C1.");
 puts("If source plaintext P1 changes before encryption, C1 changes and this affects");
 puts("C2, C3, and every later ciphertext block through the CBC chaining dependency.");
 return 0;
}
