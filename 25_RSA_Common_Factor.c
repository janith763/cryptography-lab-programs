/* Q25: Demonstrate how a plaintext block sharing a factor with n can reveal a factor. */
#include <stdio.h>
long long gcd(long long a,long long b){while(b){long long t=a%b;a=b;b=t;}return a;}
int main(void){long long n,m;printf("Enter n: ");if(scanf("%lld",&n)!=1)return 1;printf("Enter plaintext block m: ");if(scanf("%lld",&m)!=1)return 1;long long g=gcd(m,n);printf("gcd(m,n)=%lld\n",g);if(g==1)puts("No nontrivial common factor found.");else if(g==n)puts("m is a multiple of n; no proper factor is revealed.");else printf("Factor revealed: %lld; other factor = %lld\n",g,n/g);puts("A proper factor of n compromises RSA because n can then be factored.");return 0;}
