# Valgrind Exercise

## Assignment Answers

**Question:** What happens when the executable is linked statically? Does Valgrind still detect those same bugs? Why or why not?

**Answer:**
When the executable is linked statically (using the `-static` flag), the resulting binary includes not just the user code, but also all the system libraries (like `glibc`) it depends on.

**Does Valgrind still detect the bugs?**
Technically **yes**, Valgrind can often still detect the bugs, but the output becomes significantly "noisier" and harder to read. In many cases, it may report extensive "false positives" or errors that originate from the system libraries (e.g., `__pthread_initialize_minimal`) rather than user code.

**Why?**
Valgrind works by replacing standard memory allocators (like `malloc` and `free`) with its own versions to track memory usage. When linked statically, the system's memory allocators are baked into the binary and Valgrind cannot easily intercept them. This often leads to Valgrind failing to track allocations properly or reporting uninitialized values that are actually internal optimizations within the C standard library.


