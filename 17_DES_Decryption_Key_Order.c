#include <stdio.h>
int main(void){int i;puts("DES decryption uses the normal round function with subkeys in reverse order:");
for(i=16;i>=1;i--)printf("Round %2d uses K%d\n",17-i,i);
puts("Generate the same subkeys, then apply K16, K15, ..., K1.");return 0;}
