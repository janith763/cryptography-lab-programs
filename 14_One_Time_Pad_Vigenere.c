#include <stdio.h>
#include <ctype.h>
int main(void){
 char p[]="send more money", target[]="cash not needed", c[30];
 int k[]={9,0,1,7,23,15,21,14,11,11,2,8,9},v[20],n=0,i,j=0;
 for(i=0;p[i];i++)if(isalpha((unsigned char)p[i]))v[n++]=toupper((unsigned char)p[i])-'A';
 printf("Plaintext: SENDMOREMONEY\nCiphertext: ");
 for(i=0;i<n;i++){c[i]='A'+(v[i]+k[i])%26;putchar(c[i]);}c[n]='\0';puts("");
 printf("Key stream to make that ciphertext decrypt to CASHNOTNEEDED:\n");
 for(i=0;target[i];i++)if(isalpha((unsigned char)target[i])){int x=toupper((unsigned char)target[i])-'A';printf("%d ",(c[j++]-'A'-x+26)%26);}
 puts("");return 0;
}
