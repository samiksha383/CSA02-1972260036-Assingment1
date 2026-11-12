\# TASK 8 – Trace the Compilation Process



1\. \*\*Preprocessing (`gcc -E` -> `.i`):\*\* Strips all comments, expands `#include <stdio.h>` and `"billing.h"`, and substitutes macros (`SLAB1\_UNITS`, `RATE2\_PAISE`, `DBG\_PRINT`).

2\. \*\*Compilation (`gcc -S` -> `.s`):\*\* Translates preprocessed C code into x86-64 assembly instructions (`movl`, `subl`, `imull`, `call`).

3\. \*\*Assembly (`gcc -c` -> `.o`):\*\* Assembles the `.s` file into machine-code binary object format (COFF/PE on Windows).

4\. \*\*Linking (`gcc` -> `.exe`):\*\* Resolves external library calls (`printf`) against the C runtime library (`ucrtbase.dll`) to produce the final executable.



\## Error Classification Examples

\* \*\*Compile-time Error:\*\* Missing semicolon `;` or type mismatch caught during syntax/semantic analysis.

\* \*\*Link-time Error:\*\* Calling `compute\_bill()` when its definition is missing (`undefined reference to compute\_bill`).

\* \*\*Run-time Error:\*\* Dividing by zero (`units / 0`) or invalid memory access during program execution.

\* \*\*Compiler Warnings (`-Wall -Wextra`):\*\* Caught unused variables and signed/unsigned comparison mismatches (`int` vs `unsigned int`), resolved via explicit casting.



\## Alternative Concept (Multi-File Separate Compilation)

Splitting the project into `input.c`, `tariff.c`, and `report.c` means modifying `tariff.c` only requires recompiling `tariff.c` ($O(1)$ file) and relinking, instead of recompiling every source file ($O(F)$ files). Each `.o` file adds \~1–2 KB of symbol table metadata.



