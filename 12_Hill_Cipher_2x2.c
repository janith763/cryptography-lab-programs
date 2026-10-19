#include <stdio.h>
#include <ctype.h>
#include <string.h>
int mod26(int x){x%=26;return x<0?x+26:x;}
int main(void){
 char msg[]="meet me at the usual place at ten rather than eight oclock", p[200];
 int i,n=0;
 for(i=0;msg[i];i++) if(isalpha((unsigned char)msg[i])) p[n++]=toupper((unsigned char)msg[i]);
 if(n%2)p[n++]='X';
 printf("Key matrix: [9 4; 5 7]\nPlaintext (letters only): %.*s\n",n,p);
 printf("Calculations per pair: C1=(9P1+4P2) mod 26; C2=(5P1+7P2) mod 26\nCiphertext: ");
 for(i=0;i<n;i+=2){int x=p[i]-'A',y=p[i+1]-'A';putchar('A'+mod26(9*x+4*y));putchar('A'+mod26(5*x+7*y));}
 printf("\nInverse matrix mod 26: [5 12; 15 25]\nDecryption: P1=(5C1+12C2) mod 26; P2=(15C1+25C2) mod 26\n");
 return 0;
}
