*This project has been created as part of the 42 curriculum by wiaon-in.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of integers using two stacks (A and B) with a limited set of operations, and to do so in the **fewest operations possible**.

### Allowed operations

| Operation | Effect |
|-----------|--------|
| `sa` | Swap the top 2 elements of stack A |
| `sb` | Swap the top 2 elements of stack B |
| `ss` | `sa` + `sb` simultaneously |
| `pa` | Push the top of stack B onto stack A |
| `pb` | Push the top of stack A onto stack B |
| `ra` | Rotate stack A — top element goes to bottom |
| `rb` | Rotate stack B — top element goes to bottom |
| `rr` | `ra` + `rb` simultaneously |
| `rra` | Reverse rotate stack A — bottom element goes to top |
| `rrb` | Reverse rotate stack B — bottom element goes to top |
| `rrr` | `rra` + `rrb` simultaneously |

### Algorithm

- **n ≤ 5** — hardcoded optimal sequences (≤ 2 ops for n=3, ≤ 12 for n=5)
- **n > 5** — Turkish sort (greedy cost-based insertion):
  1. Push all elements except 3 from A → B
  2. Sort the 3 remaining elements in A
  3. For each element in B, calculate the cheapest rotation cost to insert it into the correct position in A (using `rr`/`rrr` when both stacks rotate in the same direction)
  4. Rotate A to bring the minimum element to the top

### Benchmark results

| Input size | Operations | Limit for full score |
|------------|-----------|----------------------|
| 100 numbers | ~550–620 | < 700 |
| 500 numbers | ~5100–5500 | ≤ 5500 |

---

## Instructions

### Requirements

- Linux or WSL (Windows Subsystem for Linux)
- `cc` compiler with `-Wall -Wextra -Werror`

### Compile

```bash
make          # compile push_swap
make bonus    # compile checker (bonus)
make re       # clean and recompile everything
make clean    # remove object files
make fclean   # remove object files and binaries
```

### Run

```bash
# Sort integers — outputs the operation sequence
./push_swap 3 1 2 5 4

# Count total operations
./push_swap 3 1 2 5 4 | wc -l

# Validate with checker (bonus)
ARG="3 1 2 5 4"
./push_swap $ARG | ./checker $ARG
```

### Error cases (print `Error` to stderr, exit 1)

```bash
./push_swap 1 1        # duplicate
./push_swap abc        # not an integer
./push_swap 2147483648 # overflow
```

### No output cases

```bash
./push_swap            # no arguments
./push_swap 1 2 3      # already sorted
```

### Benchmark

```bash
# Test 100 numbers (must be < 700 ops for full score)
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l

# Test 500 numbers (must be ≤ 5500 ops for full score)
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

---

## Resources

### References

- [Turkish Sort / Greedy insertion explained](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Push swap visualizer](https://github.com/o-reo/push_swap_visualizer) — useful for debugging the operation sequence
- 42 push_swap subject (en.subject.pdf)

### AI usage

This project was developed with assistance from **Claude (Anthropic)** as a learning tool. AI was used for:

- **Project structure** — planning the file layout and function decomposition to comply with 42 Norminette rules (≤ 25 lines/function, ≤ 5 functions/file)
- **Algorithm explanation** — understanding the Turkish sort / greedy cost-based insertion approach and how combined rotations (`rr`/`rrr`) reduce operation count
- **Code generation** — generating the initial implementation of all source files, which was then reviewed and understood
- **Debugging** — identifying two critical bugs: (1) `find_target` using a global minimum (`idx==0`) that could be in stack B during insertion, and (2) `ft_strjoin` crashing on `NULL` input in the checker
- **Norminette compliance** — restructuring functions and splitting files to pass norminette without changing logic
- **Testing** — writing `test_input.sh` covering 45 cases including edge cases (INT_MIN, INT_MAX, -0, overflow, duplicates)

All code was understood and validated by the student before submission.
