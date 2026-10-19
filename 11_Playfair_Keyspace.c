#include <stdio.h>
#include <math.h>

int main(void) {
    long double all = 1.0L, effective = 1.0L;
    int i;
    for (i = 1; i <= 25; i++) all *= i;       /* 25! arrangements */
    for (i = 1; i <= 24; i++) effective *= i; /* 24! after factor 25 */

    printf("All key-square arrangements = 25! = %.0Lf\n", all);
    printf("log2(25!) = %.3Lf, approximately 2^84.\n", logl(all) / logl(2.0L));
    printf("Counting cyclic row and column shifts as equivalent gives 25!/25 = 24!.\n");
    printf("Effective key count = %.0Lf, approximately 2^%.0Lf.\n",
           effective, logl(effective) / logl(2.0L));
    return 0;
}
