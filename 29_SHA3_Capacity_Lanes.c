#include <stdio.h>
int main(){int rate=1024/64,capacity=(1600-1024)/64;printf("Rate lanes: %d\\nCapacity lanes: %d\\n",rate,capacity);puts("With the Keccak permutation ignored, absorbing message blocks affects only rate lanes.");puts("The original capacity lanes remain zero forever; no finite number of blocks is sufficient.");return 0;}
