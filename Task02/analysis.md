# Task 2 Analysis – Choosing Data Types

### 1. Selected Data Types
* `unsigned short` (2 bytes) for meter readings (0 to 65535).
* `unsigned int` (4 bytes) for units consumed.
* `long` (8 bytes) for financial values tracked directly in whole Paise.

### 2. Resolution of Precision Drift
Floating-point (`float`) numbers suffer from rounding errors because they cannot precisely represent specific decimals in binary. Over 800,000 district entries, these small drops add up to large financial errors. Storing money as an integer in whole paise achieves exact calculations down to the single digit.

### 3. Rollover Assessment
When the counter switches from 65400 to 120, subtracting them gives `-65280`. Unsigned 16-bit math wraps this negative value using modulo 65536:
`-65280 + 65536 = 256 units`
