#include "billing.h"

unsigned int consumption(meter_t previous, meter_t current) {
    unsigned int u = (meter_t)(current - previous);
    DBG_PRINT("prev=%u, curr=%u -> units=%u", previous, current, u);
    return u;
}

long compute_bill(int units) {
    long paise = FIXED_CHARGE_PAISE;
    if (units > SLAB2_UNITS) {
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE + (SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE;
    } else if (units > SLAB1_UNITS) {
        paise += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }
    DBG_PRINT("units=%d -> total_paise=%ld", units, paise);
    return paise;
}

int main(void) {
    unsigned int u = consumption(65400, 120);
    long bill = compute_bill((int)u);
    printf("Final Bill: Rs %ld.%02ld\n", bill / 100, bill % 100);
    return 0;
}
