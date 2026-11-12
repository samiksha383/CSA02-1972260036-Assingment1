#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint64_t slab1_wh;
    uint64_t slab2_wh;
    int64_t rate1_paise_kwh;
    int64_t rate2_paise_kwh;
    int64_t rate3_paise_kwh;
    int64_t fixed_charge_paise;
    int peak_start_hr;
    int peak_end_hr;
    int peak_multiplier_pct; /* 120 = +20% ToD peak surcharge */
} SmartTariff;

int load_tariff(const char *path, SmartTariff *t) {
    FILE *fp = fopen(path, "r");
    if (!fp) return 0;
    int ok = fscanf(fp, "%llu %llu %lld %lld %lld %lld %d %d %d",
                    (unsigned long long *)&t->slab1_wh,
                    (unsigned long long *)&t->slab2_wh,
                    (long long *)&t->rate1_paise_kwh,
                    (long long *)&t->rate2_paise_kwh,
                    (long long *)&t->rate3_paise_kwh,
                    (long long *)&t->fixed_charge_paise,
                    &t->peak_start_hr,
                    &t->peak_end_hr,
                    &t->peak_multiplier_pct) == 9;
    fclose(fp);
    return ok;
}

int64_t compute_interval_charge(uint64_t delta_wh, int hour, int slab_tier, const SmartTariff *t) {
    int64_t rate = (slab_tier == 3) ? t->rate3_paise_kwh :
                   (slab_tier == 2) ? t->rate2_paise_kwh : t->rate1_paise_kwh;

    /* Exact integer math: (Wh * paise_per_kWh) / 1000 */
    int64_t paise = (int64_t)((delta_wh * (uint64_t)rate) / 1000ULL);

    /* Apply 20% Time-of-Day surcharge between 18:00 and 22:00 */
    if (hour >= t->peak_start_hr && hour < t->peak_end_hr) {
        paise = (paise * t->peak_multiplier_pct) / 100;
    }
    return paise;
}

int main(void) {
    SmartTariff cfg;
    if (!load_tariff("Task12/tariff.cfg", &cfg)) {
        fprintf(stderr, "Error: Could not load Task12/tariff.cfg\n");
        return 1;
    }

    uint64_t interval_wh = 2000; /* 2 kWh in a 15-min interval */
    int64_t offpeak_paise = compute_interval_charge(interval_wh, 14, 3, &cfg);
    int64_t peak_paise    = compute_interval_charge(interval_wh, 19, 3, &cfg);

    printf("=== Smart Meter Time-of-Day Billing (Loaded from tariff.cfg) ===\n");
    printf("Interval Usage: %llu Wh (2.000 kWh) in Slab 3 (Rs 4.50/kWh)\n",
           (unsigned long long)interval_wh);
    printf("Off-Peak (14:00): Rs %lld.%02lld\n",
           (long long)(offpeak_paise / 100), (long long)(offpeak_paise % 100));
    printf("Peak     (19:00): Rs %lld.%02lld (+20%% ToD Surcharge)\n",
           (long long)(peak_paise / 100), (long long)(peak_paise % 100));
    return 0;
}
