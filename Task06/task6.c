#include <stdio.h>

int main(void) {
    unsigned int house_id;
    long prev, curr;

    /* 1. Demonstrate wrong format specifier risk (commented out to prevent UB crash, explained in output) */
    long long big_val = 76000000000LL; /* Rs 76 Crore in paise */
    printf("=== Format Specifier Check ===\n");
    printf("Correct (%%lld): %lld paise\n", big_val);
    printf("Wrong   (%%d)  : %d paise (Truncated 64-bit to 32-bit!)\n\n", (int)big_val);

    /* 2. Input Validation using scanf return value */
    printf("Enter House ID, Previous Reading, Current Reading: ");
    if (scanf("%u %ld %ld", &house_id, &prev, &curr) != 3) {
        fprintf(stderr, "Error: Invalid input. Please enter numeric values only.\n");
        return 1;
    }

    if (prev < 0 || prev > 65535 || curr < 0 || curr > 65535) {
        fprintf(stderr, "Error: Meter readings must be between 0 and 65535.\n");
        return 1;
    }

    unsigned int units = (unsigned short)((unsigned short)curr - (unsigned short)prev);
    long paise = 5000L;
    if (units > 200) {
        paise += (long)(units - 200) * 450L + 100L * 225L;
    } else if (units > 100) {
        paise += (long)(units - 100) * 225L;
    }

    /* 3. Formatted Rupees and Paise Output */
    printf("House #%u | Units Consumed: %u | Total Bill: Rs %ld.%02ld\n",
           house_id, units, paise / 100, paise % 100);
    return 0;
}
