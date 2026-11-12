#include <stdio.h>

// Properly parenthesized macros to protect expressions against precedence errors
#define RUPEES_TO_PAISE(x) ((long)((x) * 100L))
#define SQUARE(x)          ((x) * (x))
#define MAX(a, b)          ((a) > (b) ? (a) : (b))

int main(void) {
    // 1. Test macro conversion from fractional rupees to safe whole paise
    long cash_paise = RUPEES_TO_PAISE(45.50);
    
    // 2. Test SQUARE macro with an expression input (parentheses ensure it resolves as 6*6=36, not 5+1*5+1=11)
    int complex_square = SQUARE(5 + 1);
    
    // 3. Test MAX macro evaluation
    int val_a = 10;
    int val_b = 20;
    int maximum_value = MAX(val_a, val_b);

    printf("Converted Rupees to Paise: %ld\n", cash_paise);
    printf("Square of expression (5 + 1): %d\n", complex_square);
    printf("Maximum calculated value: %d\n", maximum_value);

    return 0;
}
