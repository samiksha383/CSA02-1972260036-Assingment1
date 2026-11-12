\# TASK 7 – Control Type Conversion and Precision



\* \*\*Implicit Conversions:\*\* In `units / 100`, both operands are `int`, causing integer division truncation before assignment to `double`. When mixing `int` and `unsigned int`, C promotes the signed `int` to `unsigned int`, turning `-5` into `4294967291`.

\* \*\*Explicit Cast Overflow:\*\* Casting a 64-bit value above `2,147,483,647` to a 32-bit `int` discards the upper 32 bits, producing corrupted numbers.

\* \*\*Rounding Rule:\*\* Converting fractional rupees to integer paise uses `(long)(rupees \* 100.0 + 0.5)` to round half-up accurately.

\* \*\*Alternative Concept (Float Rounded Once at End):\*\* Accumulating in `float` (4 bytes) takes $O(1)$ time per addition, but rounding error grows as $O(n \\cdot \\epsilon)$ across $n$ bills, causing massive drift (thousands of rupees) at $n = 800,000$ bills.



