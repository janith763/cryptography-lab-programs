#include <stdio.h>
#include <ctype.h>
int main(void){
 char s[3000],ch;int k,i;
 printf("Enter ciphertext: ");if(!fgets(s,sizeof s,stdin))return 1;
 printf("All 26 shift candidates (shift 0 to 25):\n");
 for(k=0;k<26;k++){printf("%2d: ",k);for(i=0;s[i];i++){ch=s[i];if(isalpha((unsigned char)ch)){int base=isupper((unsigned char)ch)?'A':'a';putchar(base+(ch-base-k+26)%26);}else putchar(ch);} }
 return 0;
}
