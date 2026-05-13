# Dominator Algorithm

Algorithms project that solves the **Dominator (Majority Element)** problem on an array of integers.

## Problem Definition

The **dominator** (majority element) is a value `x` that appears in the array **strictly more than** `N / 2` times—i.e. its frequency is **greater than** half the array length.

- If such an element exists, it is the **dominator** and the program prints it together with the **first index** where it occurs.
- If no element satisfies this condition, the program prints that **no dominator** was found.

---

## Team

| Name |
|------|
| Nour Ibrahim |
| Giovany George |
| Mohamed Alaa |
| Abdullah Nasser |
| Sara Hamdy |
| Ganna Emad |

---

## Project Structure

| Directory | Description |
|-----------|-------------|
| `recursive/` | **Recursive** solution in two phases: pick a candidate, then verify its frequency. |
| `non-reccursive/` | **Non-recursive** **brute-force** solution using nested loops. |

Each version reads `N` and the array elements from standard input, then calls `dominator`.

---

## What the Code Does

1. Reads the array size `N` and the elements.
2. Looks for a value that occurs **more than half** of `N` times.
3. If found: prints the value and the **first** index where it appears.
4. If not found: prints that no dominator exists (or a message for an empty array when `N = 0`).

---

## Complexity

### Recursive version (`recursive/main.c`)

| | Complexity | Notes |
|---|------------|--------|
| **Time** | **O(N)** | One pass for the candidate, one pass to count frequency, one pass to find the first index. |
| **Space** | **O(N)** | Recursion depth can reach `N` in the worst case (`findCandidate`, `countFreq`, `findIndex`). |

Idea: a **Boyer–Moore–style** candidate phase, then a **verification** pass over the full array.

### Non-recursive version (`non-reccursive/main.c`)

| | Complexity | Notes |
|---|------------|--------|
| **Time** | **O(N²)** | For each index `i`, the inner loop scans all `N` elements. |
| **Space** | **O(1)** | Only a few local counters; no recursion stack proportional to `N`. |

---

## Pseudocode

### 1) Recursive (candidate + verification)

```
function FIND_CANDIDATE(A, N, i, candidate, count):
    if i == N:
        return
    if count == 0:
        candidate ← A[i]
        count ← 1
    else if A[i] == candidate:
        count ← count + 1
    else:
        count ← count - 1
    FIND_CANDIDATE(A, N, i + 1, candidate, count)

function COUNT_FREQ(A, N, candidate, i):
    if i == N:
        return 0
    return (1 if A[i] == candidate else 0) + COUNT_FREQ(A, N, candidate, i + 1)

function FIND_INDEX(A, N, candidate, i):
    if i == N:
        return -1
    if A[i] == candidate:
        return i
    return FIND_INDEX(A, N, candidate, i + 1)

function DOMINATOR(A, N):
    if N == 0:
        print "No dominator (empty array)"
        return
    candidate ← A[0]
    count ← 1
    FIND_CANDIDATE(A, N, 1, candidate, count)
    freq ← COUNT_FREQ(A, N, candidate, 0)
    if freq ≤ floor(N / 2):   // in C: freq <= N / 2 with integer division
        print "No dominator found."
        return
    index ← FIND_INDEX(A, N, candidate, 0)
    print candidate, index
```

### 2) Non-recursive (direct search)

```
function DOMINATOR(A, N):
    if N == 0:
        print "No dominator (empty array)"
        return
    for i from 0 to N - 1:
        candidate ← A[i]
        count ← 0
        for j from 0 to N - 1:
            if A[j] == candidate:
                count ← count + 1
        if count > N / 2:
            print candidate, i
            return
    print "No dominator found."
```

---

## Build and Run

The project includes **Code::Blocks** project files (`.cbp`). You can also compile manually:

```bash
# Recursive
gcc -o dominator_recursive recursive/main.c

# Non-recursive
gcc -o dominator_iterative non-reccursive/main.c
```

Run the executable and enter `N`, then the `N` elements when prompted.

### Example

**Input:** `N = 6`, elements: `1 2 3 3 3 3`  
The value `3` appears 4 times, and `4 > 6 / 2`, so **`3` is the dominator**.

---

## References

- [Boyer–Moore majority vote algorithm](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm) — related idea to the candidate phase in the recursive solution.
>>>>>>> 19f23e0 (version 2)
