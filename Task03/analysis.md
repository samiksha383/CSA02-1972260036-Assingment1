# Task 3 Analysis – Define Constants

### 1. Constant Management Strategy
Using `#define` preprocessor macros allows us to update the entire billing engine's tariff table from a single location, preventing errors where updates are applied only partially.

### 2. Alternative Concept Evaluation
If using `const` variables instead of `#define`:
* Type-checking is strictly verified by the compiler.
* Variables are visible inside debuggers like GDB.
* Modern optimizing compilers inline primitive values directly into assembly instructions, meaning runtime speed stays identical.
