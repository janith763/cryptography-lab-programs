/* Q24: Find RSA private exponent for e=31, n=3599. */
#include <stdio.h>
long long egcd(long long a,long long b,long long*x,long long*y){if(!b){*x=1;*y=0;return a;}long long u,v,g=egcd(b,a%b,&u,&v);*x=v;*y=u-(a/b)*v;return g;}
long long inverse(long long a,long long m){long long x,y;egcd(a,m,&x,&y);return (x%m+m)%m;}
int main(void){long long n=3599,e=31,p=0,q=0;for(long long i=2;i*i<=n;i++)if(n%i==0){p=i;q=n/i;break;}if(!p)return 1;long long phi=(p-1)*(q-1),d=inverse(e,phi);printf("p=%lld, q=%lld\nphi(n)=%lld\nPrivate key d=%lld\n",p,q,phi,d);return 0;}
