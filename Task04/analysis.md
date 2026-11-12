# Task 4 Analysis – Safe Macro Usage

### 1. Order of Operations Protection
Macros perform simple text replacement. Writing `#define SQUARE(x) x * x` turns `SQUARE(5 + 1)` into `5 + 1 * 5 + 1 = 11` due to operator precedence. Enclosing all terms in brackets as `((x) * (x))` guarantees it solves as `(5+1) * (5+1) = 36`.

### 2. Argument Double-Evaluation Avoidance
A macro like `#define MAX(a, b) ((a) > (b) ? (a) : (b))` evaluates its parameters multiple times. If an increment variable like `i++` is passed, it executes twice, corrupting your index. In these situations, using a `static inline` function is much safer.
