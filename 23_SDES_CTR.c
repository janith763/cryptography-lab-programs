/* Q23: S-DES counter mode, 8-bit blocks. Educational implementation. */
#include <stdio.h>
int P10[]={3,5,2,7,4,10,1,9,8,6},P8[]={6,3,7,4,8,5,10,9},IP[]={2,6,3,1,4,8,5,7},IPI[]={4,1,3,5,7,2,8,6},EP[]={4,1,2,3,2,3,4,1},P4[]={2,4,3,1};
int S0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}},S1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
int perm(int x,int*p,int n,int b){int y=0;for(int i=0;i<n;i++)y=(y<<1)|((x>>(b-p[i])&1));return y;}
void keys(int key,int*k1,int*k2){int p=perm(key,P10,10,10),l=p>>5,r=p&31;l=((l<<1)|(l>>4))&31;r=((r<<1)|(r>>4))&31;*k1=perm((l<<5)|r,P8,8,10);l=((l<<2)|(l>>3))&31;r=((r<<2)|(r>>3))&31;*k2=perm((l<<5)|r,P8,8,10);}
int sb(int x,int S[4][4]){return S[((x&8)>>2)|(x&1)][(x>>1)&3];}
int fk(int x,int k){int l=x>>4,r=x&15,e=perm(r,EP,8,4)^k,p=perm((sb(e>>4,S0)<<2)|sb(e&15,S1),P4,4,4);return (((l^p)<<4)|r);}
int sw(int x){return ((x&15)<<4)|(x>>4);}
int enc(int x,int k1,int k2){x=perm(x,IP,8,8);x=sw(fk(x,k1));x=fk(x,k2);return perm(x,IPI,8,8);}
void bits(int x){for(int i=7;i>=0;i--)putchar(((x>>i)&1)+'0');}
int main(void){int key=0b0111111101,p[]={1,2,4},c[3],r[3],k1,k2;keys(key,&k1,&k2);
 for(int i=0;i<3;i++){int stream=enc(i,k1,k2);c[i]=p[i]^stream;r[i]=c[i]^stream;}
 printf("Ciphertext: ");for(int i=0;i<3;i++){bits(c[i]);putchar(' ');}puts("");
 printf("Decrypted:  ");for(int i=0;i<3;i++){bits(r[i]);putchar(' ');}puts("");
 puts("Counter begins at 00000000; plaintext blocks: 00000001 00000010 00000100");
 puts("Compare with course vector; S-DES conventions may vary.");return 0;}
