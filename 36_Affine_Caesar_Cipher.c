#include <stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){int a,b;char s[256];printf("Enter a and b: ");if(scanf("%d%d",&a,&b)!=2)return 1;if(gcd(a,26)!=1){puts("Invalid: gcd(a,26) must equal 1 for one-to-one encryption.");return 1;}getchar();printf("Uppercase plaintext: ");fgets(s,sizeof s,stdin);printf("Ciphertext: ");for(int i=0;s[i]&&s[i]!='\\n';i++)if(s[i]>='A'&&s[i]<='Z')putchar('A'+(a*(s[i]-'A')+b)%26);else putchar(s[i]);puts("");return 0;}
