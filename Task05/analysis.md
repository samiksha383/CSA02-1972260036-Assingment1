# TASK 5 - Organise the Program with Header Files and Conditional Compilation

* **Program Structure:** Shared constants, macros, type definitions (`meter_t`), and function prototypes live in `billing.h`. Implementation logic and `main()` live in `task5.c`.
* **Include Guards (`#ifndef BILLING_H` ... `#endif`):** Prevent duplicate definition compiler errors if `billing.h` is included multiple times across a multi-file project.
* **`#include <file>` vs. `#include "file"`:** Angle brackets search standard system header directories (`stdio.h`). Double quotes search the local project directory first (`billing.h`).
* **Conditional Compilation (`#ifdef DEBUG`):** Compiling with `-DDEBUG` enables intermediate diagnostic logs. Compiling without it replaces `DBG_PRINT` with `((void)0)`, removing all debug overhead at compile time.
* **Alternative Concept (Runtime `if (debug)`):** Keeping debug code inside a runtime `if` leaves format strings and branch instructions in the final binary (increasing executable size) and executes an extra $O(1)$ conditional check on every function call.
