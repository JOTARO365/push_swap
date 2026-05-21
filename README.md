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

This project was built entirely with **Claude (Anthropic)** as the primary implementation tool. The student directed the work, asked questions to understand each step, and validated the results. Below is an honest account of what AI did:

**Architecture & planning**
- Designed the full file layout (15 `.c` files) to satisfy Norminette's ≤ 25 lines/function and ≤ 5 functions/file rules before writing any code
- Chose linked list over array-based stack and decided on index normalization (rank 0..n-1) to simplify the algorithm

**Algorithm**
- Explained and implemented the Turkish sort (greedy cost-based insertion): push all to B → sort 3 → insert cheapest back to A
- Implemented the signed cost function (`cost_of`) and combined-rotation optimization (`rr`/`rrr`) that keeps operation count under 700 for 100 numbers and 5500 for 500 numbers

**All source code**
- Wrote every `.c` and `.h` file from scratch: `stack.c`, `parse.c`, `validate.c`, `normalize.c`, `utils.c`, all 4 ops files, `sort_small.c`, `sort_large.c`, `cost.c`, `move.c`, `checker_bonus.c`, `push_swap.h`, `Makefile`
- Implemented libft additions: `get_next_line` (multi-fd linked-list variant), `ft_printf` (7 specifiers), and a fixed `ft_strjoin`

**Debugging**
- Found and fixed `find_target` returning an out-of-bounds position because `find_min_pos` searched for `idx==0` which can be in stack B during insertion — replaced with `find_min_in_a` that searches actual current contents of A
- Found and fixed `ft_strjoin` segfaulting when called with `NULL` as first argument (get_next_line's initial stash), by adding NULL guards before `ft_strlen`
- Resolved all Norminette violations by splitting `parse.c` → `validate.c`, moving `get_at` between files, and inlining `combined_cost` into `pick_cost`

**Testing**
- Wrote `test_input.sh` — 45 cases covering sorted input, error cases (duplicates, overflow, invalid chars, empty string), edge values (INT_MIN, INT_MAX, -0, +sign), and operation count benchmarks
- Wrote `test_eval.sh` — 32 cases replicating every section of the official eval sheet, including the exact command sequences specified in the grading rubric

**Learning materials**
- Created `practice/` directory with skeleton versions of all 24 files (comments only, no implementation) and `GUIDE.txt` — a 13-phase implementation roadmap for the student to rewrite the entire project independently as a learning exercise. This directory is not part of the submission — the student will implement everything from scratch using it as a guide.
