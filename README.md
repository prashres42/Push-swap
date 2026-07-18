*This project has been created as part of the 42 curriculum by prashres and ppourraj.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers in ascending order using a second, auxiliary stack, with the smallest possible number of operations — and to do so as efficiently as possible in terms of both **instruction count** and **algorithmic complexity**.

The program takes an unordered list of integers as command-line arguments, pushes them onto stack `a`, and must output a sequence of operations (`pa`, `pb`, `sa`, `sb`, `ss`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) that, when applied in order, results in stack `a` being fully sorted and stack `b` being empty.

This implementation goes beyond the mandatory scope by offering **multiple sorting strategies** selectable via flags, plus a benchmarking mode to compare their real-world performance:

| Mode | Flag | Algorithm | Target complexity |
|---|---|---|---|
| Simple | `--simple` | Selection sort | O(n²) |
| Medium | `--medium` | Chunk sort | O(n log n) |
| Complex | `--complex` | Radix sort | O(n log n) |
| Adaptive (default) | `--adaptive` | Chooses simple / medium / complex based on measured input disorder | varies |
| Benchmark | `--bench` | Prints operation-count metrics to stderr, combinable with any of the above | — |

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` executable at the root of the repository. The Makefile supports the standard targets:

```bash
make        # builds push_swap
make clean  # removes object files
make fclean # removes object files and the executable
make re     # fclean + make
```

### Execution

```bash
./push_swap [FLAG] arg1 arg2 [arg3 ...]
```

- Arguments must be valid integers (within `INT_MIN`–`INT_MAX`), separated by spaces, and can be passed either as multiple arguments or a single quoted string:
  ```bash
  ./push_swap 2 1 3 6 5 8
  ./push_swap "2 1 3 6 5 8"
  ```
- No duplicate values are allowed.
- If the input is already sorted, or has 0 or 1 elements, the program exits without printing anything.
- If the input is invalid, the program prints `Error` to stdout.

### Flags

```bash
./push_swap --simple 5 4 3 2 1      # force selection sort
./push_swap --medium 5 4 3 2 1      # force chunk sort
./push_swap --complex 5 4 3 2 1     # force radix sort
./push_swap --adaptive 5 4 3 2 1    # explicit adaptive mode (also the default with no flag)
./push_swap --bench 5 4 3 2 1       # run default (adaptive) strategy + print benchmark metrics
./push_swap --bench --complex 5 4 3 2 1   # combine any algorithm flag with benchmarking
```

Operations are always printed to **stdout**, one per line. Benchmark metrics (when `--bench` is used) are printed to **stderr**, so the two streams can be redirected independently:

```bash
# Verify correctness with the checker
./push_swap 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8

# Count operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Hide the operation list, only show benchmark metrics
./push_swap --bench $ARG 1>/dev/null

# Pipe operations to the checker while saving the benchmark to a file
./push_swap --bench $ARG 2>bench.log | ./checker_linux $ARG
```

### Testing with the checker

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

`checker_linux` reads the same arguments and the operation stream from stdin, replays them, and prints `OK` if the result is sorted, or `KO` otherwise.

## Algorithms

### Selection sort (`--simple`) — O(n²)

Selection sort repeatedly finds the current minimum value remaining in stack `a`, rotates it to the top with the shortest possible direction (`ra` if it's closer to the top, `rra` if it's closer to the bottom, chosen via `index <= size / 2`), and pushes it to stack `b` with `pb`. Once stack `a` is fully sorted, the accumulated elements in `b` — which end up ordered from largest to smallest, top to bottom — are pushed back onto `a` one by one with `pa`, landing in ascending order automatically.

**Why this algorithm was chosen for the simple tier:** it is the most intuitive and easiest-to-prove-correct approach — each step deterministically identifies and places a single element — which makes it a solid baseline implementation. Its main drawback is that finding the minimum costs O(n) per iteration, repeated n times, giving O(n²) total complexity and a comparably high operation count on larger inputs. This is an intentional trade-off: `--simple` favors simplicity and correctness over efficiency, and is meant to be used on small inputs or as a fallback within the adaptive mode.

### Chunk sort (`--medium`) — O(n√n)

Chunk sort divides stack `a` into a fixed number of value ranges ("chunks") sized so that each chunk holds roughly `size / chunk_count` elements. Elements are pushed to stack `b` chunk by chunk (smallest range first), so that `b` fills up in mostly-sorted order without needing to compute an exact global rank for every value up front. Within each chunk, the element closest to the top of `a` matching that range is prioritized to minimize rotation cost. Once every element is on `b`, the stack is pushed back to `a` in a way that preserves the resulting order.

**Why this algorithm was chosen for the medium tier:** chunking is a well-known middle ground between the simplicity of selection sort and the full radix approach — it avoids the O(n²) minimum-search cost of selection sort by grouping values instead of scanning for an exact minimum every time, bringing the total complexity down to roughly O(n log n) for a well-tuned chunk size, while remaining considerably simpler to reason about and debug than a full radix sort. It offers a good balance of operation count and implementation complexity, making it well suited to mid-sized inputs (roughly 100–500 elements).

### Radix sort (`--complex`) — O(n√n)

Radix sort treats each value by its **binary representation** rather than direct comparisons. Every value in stack `a` is first assigned a rank/index (via `assign_indexes`) so it can be sorted purely on bits, independent of the original values' magnitude. The algorithm then processes each bit position, from least significant to most significant: for every element, if the current bit is `0`, it stays at the top of `a` (via a rotate); if the bit is `1`, it is pushed to `b`. After each full pass over all elements, `b` is pushed back onto `a`. Repeating this for every bit of the largest index (`log2(n)` passes) fully sorts the stack.

**Why this algorithm was chosen for the complex tier:** unlike comparison-based sorts, radix sort's complexity depends on the number of bits needed to represent the largest index rather than on pairwise comparisons, giving it O(n log n) behavior (specifically O(n · b) where `b = log2(n)` bits) with a very predictable, low operation count — which is why it is generally the standard choice for the highest-performance tier of push_swap. It requires more careful bookkeeping (index assignment, bit extraction, and knowing exactly when a full pass ends) but scales notably better than the other two approaches on large inputs.

### Adaptive mode (default / `--adaptive`)

When no algorithm flag is given, the program measures the input's **disorder** (a normalized metric describing how far the initial stack is from being sorted) and automatically selects:
- **Selection sort** for low disorder (well-suited to nearly-sorted or small inputs, where the O(n²) cost stays negligible),
- **Chunk sort** for moderate disorder,
- **Radix sort** for high disorder (where its consistent O(n log n) behavior pays off most).

This avoids the need to manually pick an algorithm per input and lets the program self-tune based on actual input characteristics rather than size alone.

## Resources

- [42 push_swap subject documentation]
- *Introduction to Algorithms* (CLRS) — chapters on sorting algorithms and radix sort, for complexity analysis background
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — quick reference for algorithm complexity comparisons
- [GeeksforGeeks — Radix Sort](https://www.geeksforgeeks.org/radix-sort/) — general explanation of radix sort adapted here to a two-stack context
- 42 peer discussions and internal project write-ups on push_swap strategy (selection sort baseline, chunk algorithm approaches, radix sort optimizations)
- GDB / VS Code C/C++ debugging documentation, used for debugging stack manipulation logic

### AI usage

- AI was used to understand deeper about parsing, algorithms and their usage. 
- AI helped us dive deeper into the logarithmic functioning of algorithms as well as grasping the concepts of sorting the data using various types of algorithms.
- Parts of README were done using the help of AI as well.

### Contribuitions

This project was developed collaboratively from start to finish, with both contributors participating equally in its design, implementation, testing, debugging, and documentation. All major technical decisions and development work were carried out jointly, reflecting an equal partnership throughout the project.

