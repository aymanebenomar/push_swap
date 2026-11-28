*This project has been created as part of the 42 curriculum by sfaraji, abenomar.*

# push_swap

## Description

push_swap sorts a list of distinct integers using two stacks, `a` and `b`, and a small set of operations. The goal is to print the shortest possible list of operations that leaves stack `a` sorted in ascending order and stack `b` empty.

The program contains four strategies:

- **Simple**: Selection Sort, O(n²)
- **Medium**: Chunk Sort, O(n√n)
- **Complex**: Binary Radix Sort, O(n log n)
- **Adaptive** (default): picks one of the three from the input's disorder

It also has a `--bench` mode and a bonus `checker` program.

## Instructions

### Compilation

```sh
make          # builds push_swap
make bonus    # builds checker
make clean    # removes object files
make fclean   # removes object files, libft.a and the programs
make re       # rebuilds everything
```

### Usage

```sh
./push_swap 3 2 5 1 4
./push_swap "3 2 5 1 4"
./push_swap --simple 3 2 5 1 4
./push_swap --medium 3 2 5 1 4
./push_swap --complex 3 2 5 1 4
./push_swap --adaptive 3 2 5 1 4
./push_swap --bench 3 2 5 1 4
```

- Operations are printed on stdout, one per line.
- Already sorted input prints nothing.
- No arguments prints nothing.
- Non-numbers, duplicates and values outside the `int` range print `Error` on stderr.
- `--bench` prints, on stderr: the disorder (%), the strategy and its complexity, the total number of operations and the count of each operation.

### Checker (bonus)

```sh
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
```

The checker reads operations from stdin and prints `OK` if `a` is sorted and `b` is empty, `KO` otherwise, and `Error` for invalid arguments or instructions.

## Operations

| Operation | Effect |
| --- | --- |
| `sa` / `sb` / `ss` | swap the top two elements of a / b / both |
| `pa` / `pb` | move the top of b to a / the top of a to b |
| `ra` / `rb` / `rr` | rotate a / b / both: the top goes to the bottom |
| `rra` / `rrb` / `rrr` | reverse rotate a / b / both: the bottom goes to the top |

## Algorithms and justification

### Preparation

- **Ranks:** every number is replaced by its rank, from `0` (smallest) to `n - 1` (biggest). Negative and very large numbers then behave the same as small ones.
- **Disorder:** we count the pairs `(i, j)` with `i < j` where `a[i] > a[j]`, and divide by the total number of pairs. Sorted input gives `0`, reversed input gives `1`. It is measured before any move.

### Simple: Selection Sort, O(n²)

Find the smallest number in `a`, rotate it to the top the shortest way (`ra` or `rra`), and `pb` it. Repeat until `a` is empty or already sorted, then `pa` everything back.

**Why:** it is the most natural algorithm with two stacks and it is very cheap on almost sorted input.
**Complexity:** each of the n numbers can cost up to about n/2 rotations, so O(n²) operations.

### Medium: Chunk Sort, O(n√n)

We use a sliding window of ranks of size `range = √n × 1.5`. `pushed` is the number of elements already in `b`.

1. **Push to b**, looking at the top of `a`:
   - `rank <= pushed`: `pb` then `rb` (small number, sent to the bottom of `b`)
   - `rank <= pushed + range`: `pb` (in the window, stays on top of `b`)
   - otherwise: `ra` (not its turn yet)
2. **Push back to a:** repeatedly bring the biggest number of `b` to the top (`rb` or `rrb`) and `pa` it.

**Why:** instead of looking for one exact number like Selection Sort, any number in the window is accepted, so far fewer rotations are needed. The `rb` keeps big numbers near the top of `b`, which makes step 2 cheap. The factor 1.5 was chosen by testing.
**Complexity:** each number waits about one window (√n) of rotations in step 1, and the biggest number of `b` is always about √n away from the top or bottom in step 2. n numbers × √n gives O(n√n) operations.

### Complex: Binary Radix Sort, O(n log n)

We look at the ranks in binary, one bit at a time, from the right (bit 0):

- bit is `1`: `ra` (stays in `a`)
- bit is `0`: `pb` (goes to `b`)
- after all n numbers: `pa` until `b` is empty

The number of passes is the number of bits of the biggest rank (`n - 1`). Each pass keeps the order of the previous one, so after the last bit the stack is sorted.

**Why:** simple to code, no recursion, and the number of operations does not depend on how messy the input is.
**Complexity:** log₂(n) passes × about n operations per pass, so O(n log n) operations. For 100 numbers: 7 passes, 1084 operations. For 500 numbers: 9 passes, 6784 operations.

### Adaptive (default)

| Disorder | Strategy |
| --- | --- |
| below 0.2 | Simple |
| 0.2 to below 0.5 | Medium |
| 0.5 and above | Complex |

Inputs of 5 numbers or fewer use a small dedicated sort instead (3 numbers in at most 2 operations).

**Why these thresholds:**

- **< 0.2:** the list is almost sorted, so the smallest number is usually near the top and Selection Sort stops early. Cheap in practice, O(n²) in the worst case.
- **0.2 – 0.5:** partly sorted. Chunk Sort only needs each number to be in the right window, not in the exact place, so it stays efficient. O(n√n).
- **≥ 0.5:** very messy. Radix Sort always costs the same, whatever the order. O(n log n).

**Space:** the two stacks (O(n)) plus the buffer of generated operations (one byte per operation).

## Resources

- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Inversions (disorder)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))
- [VisuAlgo, sorting visualizations](https://visualgo.net/en/sorting)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### Use of AI

AI was used to explore subjects in more depth.

## Contributions

**sfaraji**

- Medium strategy (Chunk Sort)
- Complex strategy (Binary Radix Sort)
- Bonus checker
- Stack operations and output

**abenomar**

- Argument and flag parsing, error handling
- Benchmark mode (`--bench`) and disorder calculation
- Simple strategy, tiny sort and adaptive selection
- Makefile

Both of us reviewed and can explain every part of the code.