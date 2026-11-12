#include <stdio.h>
#include <limits.h>

void simulate_scale(long count, const char *label) {
    long single_bill_paise = 95000L; /* 350 units = Rs 950.00 */
    float single_bill_float = 950.00f;

    int sum_int = 0;
    long sum_long = 0;
    long long sum_ll = 0;
    float sum_float = 0.0f;

    for (long i = 0; i < count; i++) {
        sum_int += (int)single_bill_paise;
        sum_long += single_bill_paise;
        sum_ll += single_bill_paise;
        sum_float += single_bill_float;
    }

    printf("=== %s (%ld households) ===\n", label, count);
    printf("Expected Exact: Rs %lld.%02lld\n", (count * 95000LL) / 100, (count * 95000LL) % 100);
    printf("int total:      Rs %d.%02d\n", sum_int / 100, sum_int % 100);
    printf("long total:     Rs %ld.%02ld\n", sum_long / 100, sum_long % 100);
    printf("long long:      Rs %lld.%02lld\n", sum_ll / 100, sum_ll % 100);
    printf("float total:    Rs %.2f\n\n", sum_float);
}

int main(void) {
    printf("System Sizes: sizeof(int)=%zu, sizeof(long)=%zu, sizeof(long long)=%zu\n\n",
           sizeof(int), sizeof(long), sizeof(long long));

    simulate_scale(4000, "Village Scale");
    simulate_scale(60000, "Taluk Scale");
    simulate_scale(800000, "District Scale");
    return 0;
}
