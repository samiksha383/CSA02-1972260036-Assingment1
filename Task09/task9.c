#include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0L
#define RATE2_PAISE 225L
#define RATE3_PAISE 450L
#define FIXED_CHARGE_PAISE 5000L

typedef unsigned short meter_t;

unsigned int calc_units(meter_t prev, meter_t curr) {
    return (meter_t)(curr - prev);
}

long calc_bill_paise(unsigned int units) {
    long total = FIXED_CHARGE_PAISE;
    if (units > SLAB2_UNITS) {
        total += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
        total += (long)(SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE;
    } else if (units > SLAB1_UNITS) {
        total += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }
    return total;
}

int main(void) {
    int n;
    printf("Enter number of households to bill: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: Invalid household count.\n");
        return 1;
    }

    long long grand_total = 0;
    for (int i = 1; i <= n; i++) {
        long prev_in, curr_in;
        printf("House %d (prev curr): ", i);
        if (scanf("%ld %ld", &prev_in, &curr_in) != 2) {
            fprintf(stderr, "Error: Non-numeric input rejected.\n");
            return 1;
        }
        if (prev_in < 0 || prev_in > 65535 || curr_in < 0 || curr_in > 65535) {
            fprintf(stderr, "Error: Reading out of 16-bit range (0-65535).\n");
            return 1;
        }

        unsigned int units = calc_units((meter_t)prev_in, (meter_t)curr_in);
        long bill = calc_bill_paise(units);
        grand_total += bill;

        printf("  -> Consumed: %u units | Bill: Rs %ld.%02ld\n",
               units, bill / 100, bill % 100);
    }

    printf("\nBatch Total (%d houses): Rs %lld.%02lld\n",
           n, grand_total / 100, grand_total % 100);
    return 0;
}
