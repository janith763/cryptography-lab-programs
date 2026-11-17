#include <stdio.h>
int main(){puts("DSA uses a per-signature secret nonce k; different k values normally give different signatures for the same message.");puts("Reusing or predicting k can reveal the DSA private key.");puts("Basic deterministic RSA signatures can repeat for the same message and padding.");puts("Modern RSA-PSS uses a random salt, so signatures can differ.");return 0;}
