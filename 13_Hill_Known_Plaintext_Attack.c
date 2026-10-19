#include <stdio.h>
int m(int x){x%=26;return x<0?x+26:x;}
int inv26(int x){int i;for(i=1;i<26;i++)if(m(x*i)==1)return i;return -1;}
int main(void){
 int p11,p21,p12,p22,c11,c21,c12,c22,d,iv;
 printf("Enter P1 column (p11 p21), P2 column (p12 p22), then C1 and C2 columns.\n");
 printf("P1: ");if(scanf("%d%d",&p11,&p21)!=2)return 1;
 printf("P2: ");if(scanf("%d%d",&p12,&p22)!=2)return 1;
 printf("C1: ");if(scanf("%d%d",&c11,&c21)!=2)return 1;
 printf("C2: ");if(scanf("%d%d",&c12,&c22)!=2)return 1;
 d=m(p11*p22-p12*p21);iv=inv26(d);
 if(iv<0){printf("Plaintext matrix is not invertible modulo 26; choose different pairs.\n");return 0;}
 printf("Recovered key matrix:\n[%d %d]\n[%d %d]\n",
 m(iv*(c11*p22-c12*p21)),m(iv*(-c11*p12+c12*p11)),
 m(iv*(c21*p22-c22*p21)),m(iv*(-c21*p12+c22*p11)));
 return 0;
}
