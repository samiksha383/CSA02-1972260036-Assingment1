\# TASK 6 – Read and Print Data Correctly



\* \*\*Format Specifiers:\*\* `int` (`%d`), `unsigned int` (`%u`), `long` (`%ld`), `long long` (`%lld`), `float` (`%f`), `double` (`%lf`), `char` (`%c`), string (`%s`).

\* \*\*Wrong Specifier Impact:\*\* Passing a 64-bit `long long` (`76000000000LL`) to `%d` reads only the lower 32 bits, truncating the value to `-1309376512` (undefined behavior).

\* \*\*Input Validation:\*\* Checking `scanf("%u %ld %ld", ...) != 3` catches non-numeric characters (like letters) immediately before uninitialized variables are read.

\* \*\*Paise Formatting:\*\* Printing `paise / 100` and `paise % 100` with `%02ld` guarantees two decimal places (e.g., `5` paise prints as `.05`, not `.5`).

\* \*\*Alternative Concept (`fgets` + `strtol`):\*\* Reading an entire line of length $L$ with `fgets()` takes $O(L)$ time and $O(L)$ buffer space. Unlike `scanf`, which leaves invalid characters stuck in `stdin` on failure, `fgets()` consumes the entire bad line at once, making recovery clean and safe.



