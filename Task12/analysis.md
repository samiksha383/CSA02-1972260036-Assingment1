\# TASK 12 – Day-4 Design Challenge: Smart Meter Re-evaluation



\## Decision: REDESIGN



\### A. Impact Analysis

1\. \*\*Unit \& Frequency Change:\*\* Smart meters report every 15 minutes ($35,040$ readings/house/year) in \*\*Watt-hours (Wh)\*\* instead of monthly kWh.

2\. \*\*Data Type Overflow:\*\* A household using $15,000\\text{ kWh/year}$ consumes $15,000,000\\text{ Wh}$, exceeding the `65,535` limit of `uint16\_t`. Across $800,000$ district houses, annual consumption reaches $1.2 \\times 10^{13}\\text{ Wh}$, exceeding 32-bit integers ($4.29 \\times 10^9$) and requiring \*\*`uint64\_t`\*\*.

3\. \*\*Compile-Time Macros Obsolete:\*\* `#define` constants cannot be changed without recompiling and must be replaced by a runtime \*\*`SmartTariff` struct\*\* loaded from `tariff.cfg`.



\### B. Evaluation of Original Design

\* Original `uint16\_t` meter readings overflow within hours when counting Wh.

\* Original `compute\_bill(int units)` lacks timestamp awareness to apply the 20% surcharge between `18:00` and `22:00`.



\### C. Adaptation / Redesign Summary

\* Upgraded energy counters to \*\*`uint64\_t`\*\* and financial accumulators to \*\*`int64\_t`\*\* (paise).

\* Replaced `#define` constants with `load\_tariff("Task12/tariff.cfg", \&cfg)` ($O(1)$ fixed config load at startup).

\* Applied Time-of-Day surcharge using exact integer arithmetic `(paise \* 120) / 100` to avoid floating-point rounding drift.



\### D. Evidence-Based Defence

\* Handles $1.2 \\times 10^{13}\\text{ Wh}$/year at district scale with zero overflow (`uint64\_t` max is $1.84 \\times 10^{19}$).

\* Evaluates each 15-minute packet in \*\*$O(1)$\*\* time while allowing the co-operative board to update slab rates or peak hours in `tariff.cfg` with zero recompilation.



