#include <stdio.h>
int main(){puts("RSA private key leak demonstration");puts("If d is leaked, an attacker may recover the factors of the existing modulus n.");puts("Generating new e and d with the same n is NOT safe.");puts("Bob must generate fresh primes p,q and a completely new modulus n=p*q.");return 0;}
