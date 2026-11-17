#include <stdio.h>
long long pw(long long a,int e,int n){long long r=1;while(e-- >0)r=r*a%n;return r;}
int main(){int n=3233,e=17;puts("Codebook attack on textbook RSA (toy parameters):");for(int p=0;p<26;p++)printf("%c -> %lld\\n",'A'+p,pw(p,e,n));puts("An attacker precomputes all 26 values and matches ciphertexts. Deterministic per-character RSA also leaks repeated-letter patterns.");return 0;}
