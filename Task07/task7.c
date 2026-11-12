#include <stdio.h>

int main(void) {
    printf("=== Three Type Conversion Surprises ===\n");

    /* Surprise 1: Integer Division Truncation */
    int units = 150;
    double wrong_ratio = units / 100;
    double right_ratio = units / 100.0;
    printf("1. Integer Division: %d / 100 = %.2f (Expected 1.50 -> %.2f)\n",
           units, wrong_ratio, right_ratio);

    /* Surprise 2: Implicit Signed-to-Unsigned Promotion */
    int signed_diff = -5;
    unsigned int unsigned_limit = 10U;
    printf("2. Signed (-5) < Unsigned (10U) is: %s\n",
           (signed_diff < unsigned_limit) ? "TRUE" : "FALSE (Promoted to 4294967291U!)");

    /* Surprise 3: Narrowing Cast Overflow (long long -> int) */
    long long district_paise = 5000000000LL; /* Rs 5 Crore */
    int narrowed_int = (int)district_paise;
    printf("3. Casting 5000000000LL to 32-bit int gives: %d (Overflow!)\n\n", narrowed_int);

    /* Consistent Rounding Rule (+0.5 before truncation) */
    double fractional_rupees = 162.556;
    long rounded_paise = (long)(fractional_rupees * 100.0 + 0.5);
    printf("4. Rounding Rule: Rs %.3f -> %ld paise (Rs %ld.%02ld)\n\n",
           fractional_rupees, rounded_paise, rounded_paise / 100, rounded_paise % 100);

    /* Alternative Concept: Float Accumulator Drift vs Exact Paise */
    float float_sum = 0.0f;
    long long exact_paise = 0LL;
    for (int i = 0; i < 800000; i++) {
        float_sum += 162.53f;
        exact_paise += 16253LL;
    }
    printf("5. District Drift (800,000 bills of Rs 162.53):\n");
    printf("   Exact Paise Total: Rs %lld.%02lld\n", exact_paise / 100, exact_paise % 100);
    printf("   Float Total:       Rs %.2f (Drift: Rs %.2f)\n",
           float_sum, float_sum - (exact_paise / 100.0));

    return 0;
}
