# CSA02 – C Programming Assignment 1
**Grama Jyothi Rural Electricity Co-operative Billing System**

* **Student Name:** Samiksha
* **Register Number:** 1972260036
* **Compiler:** GCC 16.2.0 (`WinLibs x86_64-w64-mingw32`)
* **Compile Command:** `gcc -Wall -Wextra <source.c> -o <output.exe>`
* **Run Command:** `.\<output.exe>`

## Task Summary & Results

| Task | Folder | Summary of Findings |
| :--- | :--- | :--- |
| Task 01 | `Task01/` | Identified inputs, outputs, and integer paise rules; $O(1)$ integer vs $O(d)$ string complexity. |
| Task 02 | `Task02/` | Used `unsigned short` for 16-bit rollover (`65400 -> 120 = 256`); proved `float` drifts across 4,000 bills. |
| Task 03 | `Task03/` | Centralized tariff constants using `#define` for single-point revision. |
| Task 04 | `Task04/` | Verified macro parenthesization and double-evaluation bugs via `gcc -E`. |
| Task 05 | `Task05/` | Created `billing.h` with include guards and `-DDEBUG` conditional logging. |
| Task 06 | `Task06/` | Validated `scanf` return values and formatted integer paise as `Rs X.YY`. |
| Task 07 | `Task07/` | Demonstrated integer division, signed/unsigned promotion, and narrowing cast overflow. |
| Task 08 | `Task08/` | Generated `.i`, `.s`, `.o`, and linked `.exe` compilation stages. |
| Task 09 | `Task09/` | Tested boundary cases (`0`, `100`, `200`), rollover (`65535 -> 0`), and invalid inputs. |
| Task 10 | `Task10/` | Proved `int`/`long` overflow on Windows LLP64 at district scale (`800,000` houses); `long long` stays exact. |
| Task 11 | `Task11/` | Recommended `uint16_t`, `uint32_t`, and `int64_t` architecture. |
| Task 12 | `Task12/` | Redesigned for 15-min Wh smart meters (`uint64_t`), ToD peak pricing, and runtime `tariff.cfg`. |
