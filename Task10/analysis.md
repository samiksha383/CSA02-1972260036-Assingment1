\# TASK 10 – Compare Expectations with Execution



\## Measured Scale Comparison (Rs 950.00 per bill)



| Scale | Houses | Expected Total | `int` (4 bytes) | `long` (4 bytes on Win64) | `long long` (8 bytes) | `float` (4 bytes) |

| :--- | :--- | :--- | :--- | :--- | :--- | :--- |

| \*\*Village\*\* | `4,000` | `Rs 3,800,000.00` | Exact | Exact | Exact | Exact (`3800000.00`) |

| \*\*Taluk\*\* | `60,000` | `Rs 57,000,000.00` | \*\*OVERFLOW\*\* | \*\*OVERFLOW\*\* | Exact | Precision drift begins |

| \*\*District\*\* | `800,000` | `Rs 760,000,000.00` | \*\*OVERFLOW\*\* | \*\*OVERFLOW\*\* | Exact | Major precision loss |



\## Key Observations

\* \*\*Windows LLP64 vs. C Standard:\*\* On 64-bit Windows (`WinLibs GCC`), `sizeof(long)` is \*\*4 bytes\*\* (matching the C standard minimum of 32 bits, max `2,147,483,647`), so both `int` and `long` overflow at Taluk and District scales (`76,000,000,000` paise). Only `long long` (guaranteed $\\ge 64$ bits) remains exact.

\* \*\*Alternative Concept (`double` Accumulator):\*\* A 64-bit `double` has 53 bits of significand ($\\approx 9 \\times 10^{15}$ exact integer range) and takes 8 bytes ($O(1)$ per addition). It avoids overflow and whole-rupee loss at 800,000 bills, though binary fractional drift still makes `long long` integer paise strictly superior for financial ledgers.



