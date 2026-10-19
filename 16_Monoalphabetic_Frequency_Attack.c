#include <stdio.h>
#include <ctype.h>
int main(void){
 char s[4000],map[26];int cnt[26]={0},ord[26],i,j,t;const char *eng="ETAOINSHRDLCUMWFGYPBVKJXQZ";
 printf("Enter ciphertext: ");if(!fgets(s,sizeof s,stdin))return 1;
 for(i=0;s[i];i++)if(isalpha((unsigned char)s[i]))cnt[toupper((unsigned char)s[i])-'A']++;
 for(i=0;i<26;i++)ord[i]=i;
 for(i=0;i<26;i++)for(j=i+1;j<26;j++)if(cnt[ord[j]]>cnt[ord[i]]){t=ord[i];ord[i]=ord[j];ord[j]=t;}
 for(i=0;i<26;i++)map[ord[i]]=eng[i];
 printf("Frequency-based candidate (heuristic, not guaranteed):\n");
 for(i=0;s[i];i++){char c=s[i];if(isupper((unsigned char)c))putchar(map[c-'A']);else if(islower((unsigned char)c))putchar(tolower(map[c-'a']));else putchar(c);}
 puts("");return 0;
}
