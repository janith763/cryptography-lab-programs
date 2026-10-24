/* Q21: Educational demonstration of ECB, CBC, CFB and 1-bit/zero padding.
   Toy XOR block transform only; NOT secure encryption. */
#include <stdio.h>
#include <string.h>
#define B 4
void toy(const unsigned char *in,unsigned char *out){for(int i=0;i<B;i++)out[i]=in[i]^0xA5;}
void show(const char *s,const unsigned char *a,size_t n){printf("%s: ",s);for(size_t i=0;i<n;i++)printf("%02X ",a[i]);puts("");}
int main(void){
 unsigned char in[256],p[260],out[260],iv[B]={1,2,3,4},prev[B],x[B],stream[B];
 printf("Enter plaintext: ");if(!fgets((char*)in,sizeof in,stdin))return 1;
 size_t len=strcspn((char*)in,"\n"),n=len+1;if(n%B)n+=B-n%B;
 memcpy(p,in,len);p[len]=0x80;memset(p+len+1,0,n-len-1);show("Padded bytes",p,n);
 for(size_t i=0;i<n;i+=B)toy(p+i,out+i);show("ECB toy ciphertext",out,n);
 memcpy(prev,iv,B);for(size_t i=0;i<n;i+=B){for(int j=0;j<B;j++)x[j]=p[i+j]^prev[j];toy(x,out+i);memcpy(prev,out+i,B);}show("CBC toy ciphertext",out,n);
 memcpy(prev,iv,B);for(size_t i=0;i<n;i+=B){toy(prev,stream);for(int j=0;j<B;j++)out[i+j]=p[i+j]^stream[j];memcpy(prev,out+i,B);}show("CFB toy ciphertext",out,n);
 puts("Motivation: the marker makes the original message length unambiguous, even when");
 puts("the message already fills a complete block. Receiver can distinguish real trailing");
 puts("zero bytes from padding. Toy transform is for learning only, not secure.");
 return 0;
}
