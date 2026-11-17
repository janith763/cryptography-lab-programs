#include <stdio.h>
long long mp(long long a,long long e,long long m){long long r=1;while(e){if(e&1)r=r*a%m;a=a*a%m;e>>=1;}return r;}
int main(){long long q=23,a=5,x=6,y=15,A=mp(a,x,q),B=mp(a,y,q);printf("Alice sends %lld\\nBob sends %lld\\n",A,B);printf("Alice key=%lld, Bob key=%lld\\n",mp(B,x,q),mp(A,y,q));puts("Using x^a instead of a^x does not produce standard DH agreement.");puts("Unauthenticated DH permits a man-in-the-middle attack. Recovering x from a^x mod q is a discrete-log problem.");return 0;}
