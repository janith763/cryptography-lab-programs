/* Q22: Simplified S-DES CBC demonstration with 8-bit blocks.
   Verify bit-order/table conventions against your course's supplied test vector. */
#include <stdio.h>
int P10[]={3,5,2,7,4,10,1,9,8,6},P8[]={6,3,7,4,8,5,10,9},IP[]={2,6,3,1,4,8,5,7},IPI[]={4,1,3,5,7,2,8,6},EP[]={4,1,2,3,2,3,4,1},P4[]={2,4,3,1};
int S0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}},S1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
int perm(int x,int*p,int n,int b){int y=0;for(int i=0;i<n;i++)y=(y<<1)|((x>>(b-p[i]))&1);return y;}
void keys(int key,int*k1,int*k2){int p=perm(key,P10,10,10),l=p>>5,r=p&31;l=((l<<1)|(l>>4))&31;r=((r<<1)|(r>>4))&31;*k1=perm((l<<5)|r,P8,8,10);l=((l<<2)|(l>>3))&31;r=((r<<2)|(r>>3))&31;*k2=perm((l<<5)|r,P8,8,10);}
int sb(int x,int S[4][4]){return S[((x&8)>>2)|(x&1)][(x>>1)&3];}
int fk(int x,int k){int l=x>>4,r=x&15,e=perm(r,EP,8,4)^k,p=perm((sb(e>>4,S0)<<2)|sb(e&15,S1),P4,4,4);return (((l^p)<<4)|r);}
int sw(int x){return ((x&15)<<4)|(x>>4);}
int crypt(int x,int k1,int k2,int d){x=perm(x,IP,8,8);x=fk(x,d?k2:k1);x=sw(x);x=fk(x,d?k1:k2);return perm(x,IPI,8,8);}
void bits(int x){for(int i=7;i>=0;i--)putchar(((x>>i)&1)+'0');}
int main(void){int key=0b0111111101,iv=0b10101010,p[]={1,0x23},c[2],r[2],k1,k2;keys(key,&k1,&k2);int prev=iv;
 for(int i=0;i<2;i++){c[i]=crypt(p[i]^prev,k1,k2,0);prev=c[i];}
 printf("Ciphertext: ");for(int i=0;i<2;i++){bits(c[i]);putchar(' ');}puts("");
 prev=iv;for(int i=0;i<2;i++){r[i]=crypt(c[i],k1,k2,1)^prev;prev=c[i];}
 printf("Decrypted:  ");for(int i=0;i<2;i++){bits(r[i]);putchar(' ');}puts("");
 puts("Input vector: IV=10101010, key=0111111101, plaintext=00000001 00100011");
 puts("Compare output with course vector; S-DES conventions may vary.");return 0;}
