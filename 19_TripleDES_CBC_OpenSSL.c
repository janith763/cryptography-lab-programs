/* Compile where OpenSSL development files are installed:
   cc 19_TripleDES_CBC_OpenSSL.c -o tdes_cbc -lcrypto
   3DES is legacy; use AES-GCM for new applications. */
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
int main(void){
 unsigned char key[24]="0123456789abcdefghijklmn",iv[8]="12345678";
 unsigned char p[]="Example CBC message",c[128],r[128];int a=0,b=0,x=0;
 EVP_CIPHER_CTX *ctx=EVP_CIPHER_CTX_new();if(!ctx)return 1;
 if(EVP_EncryptInit_ex(ctx,EVP_des_ede3_cbc(),NULL,key,iv)!=1){
  puts("3DES-CBC unavailable in this OpenSSL build/provider.");EVP_CIPHER_CTX_free(ctx);return 1;}
 EVP_EncryptUpdate(ctx,c,&a,p,(int)strlen((char*)p));EVP_EncryptFinal_ex(ctx,c+a,&b);x=a+b;
 printf("Ciphertext hex: ");for(int i=0;i<x;i++)printf("%02X",c[i]);puts("");
 EVP_DecryptInit_ex(ctx,EVP_des_ede3_cbc(),NULL,key,iv);
 EVP_DecryptUpdate(ctx,r,&a,c,x);EVP_DecryptFinal_ex(ctx,r+a,&b);r[a+b]='\0';
 printf("Recovered plaintext: %s\n",r);EVP_CIPHER_CTX_free(ctx);return 0;
}
