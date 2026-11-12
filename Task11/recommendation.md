\# TASK 11 – Final Design Recommendation and Defence



\## 1. Recommended Data Types \& Preprocessor Architecture

\* \*\*Meter Readings (`uint16\_t` / `unsigned short`):\*\* 2 bytes (`0` to `65,535`). Directly models the 16-bit hardware counter and handles single rollovers via unsigned modular subtraction `(meter\_t)(curr - prev)` in $O(1)$ time without branching.

\* \*\*Consumption Units (`uint32\_t` / `unsigned int`):\*\* 4 bytes. Prevents signed/unsigned comparison bugs during slab evaluation.

\* \*\*Individual Bills \& District Totals (`int64\_t` / `long long`):\*\* 8 bytes (up to $9.22 \\times 10^{18}$ paise). Proven in Task 10 to prevent both the 32-bit `long` overflow seen on Windows LLP64 systems and the cumulative rounding drift of `float`.

\* \*\*Header \& Conditional Compilation:\*\* All constants (`SLAB1\_UNITS`, `RATE2\_PAISE`, etc.) live in a single header (`billing.h`) guarded by `#ifndef BILLING\_H`. Diagnostic logs use `#ifdef DEBUG` so production builds incur zero runtime or binary size overhead.



\## 2. How a Tariff Revision is Carried Out

1\. Open `billing.h` and modify the single macro definition (e.g., `#define RATE2\_PAISE 230`).

2\. Recompile the project once (`gcc -Wall -Wextra ...`).

3\. Every calculation across the entire application updates automatically with zero risk of partial revisions.



\## 3. Design Limitations

1\. \*\*Single Rollover Assumption:\*\* Cannot distinguish `0` units consumed from `65,536` units consumed in a single month.

2\. \*\*Compile-Time Tariffs:\*\* Every tariff change requires recompiling and redistributing the binary to village offices.

3\. \*\*Flat Monthly Resolution:\*\* Does not support 15-minute smart meter intervals or Time-of-Day (ToD) peak pricing.



\## 4. Alternative Concept (External Tariff Configuration File)

Reading $t$ tariff parameters from a startup file (`tariff.cfg`) adds $O(t)$ disk I/O startup time and $O(t)$ RAM (typically $< 100$ bytes), while eliminating the need to recompile and redistribute executables after every board tariff revision.





