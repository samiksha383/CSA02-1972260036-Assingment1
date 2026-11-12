#ifndef BILLING_H
#define BILLING_H

#include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000L

#ifdef DEBUG
#define DBG_PRINT(fmt, ...) fprintf(stderr, "[DEBUG] " fmt "\n", __VA_ARGS__)
#else
#define DBG_PRINT(fmt, ...) ((void)0)
#endif

typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current);
long compute_bill(int units);

#endif
