# Algorithm Paradigms

## 1. Brute Force

### Design Idea
Brute force solves problems by enumerating all possible candidates and checking each one. It directly implements the problem definition without optimization.

### Complexity Analysis
- **Time**: O(n) for linear search
- **Space**: O(1)

### Comparison with Higher Complexity Approach
| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Brute Force (Linear Search) | O(n) | O(1) | Simple, works on unsorted data | Slow for large n |
| Brute Force (All Subsets) | O(2^n) | O(n) | Guaranteed correct | Exponential time |

### Code Example
```cpp
// From brute-force.cpp - Linear Search
int LinearSearch(int value) {
    for(int i = 0; i < n; i++) 
        if (arr[i] == value) return i+1;
    return -1;
}
```

---

## 2. Divide and Conquer

### Design Idea
Break problem into smaller subproblems of the same type, solve recursively, then combine results. Three steps: Divide, Conquer, Combine.

### Complexity Analysis
- **Binary Search**: O(log n) time, O(1) space (iterative) / O(log n) space (recursive)
- **Fast Power (x^n)**: O(log n) time, O(log n) space (recursive) / O(1) space (iterative)

### Comparison with Higher Complexity Approach
| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| D&C Binary Search | O(log n) | O(1) | Fast, optimal for sorted arrays | Requires sorted input |
| Linear Search | O(n) | O(1) | Works on unsorted | Slower |
| D&C Power (Recursive) | O(log n) | O(log n) | Elegant, fewer multiplications | Stack overhead |
| Naive Power (Loop) | O(n) | O(1) | Simple | Slower for large n |

### Code Examples
```cpp
// From DnC-sample-1.cpp - Binary Search (Iterative)
int BinarySearch(int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) return mid;
        if (arr[mid] > value) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
```

```cpp
// From DnC-sample-2.cpp - Fast Power (Recursive)
int power(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n & 1) return x * power(x, n - 1);
    int temp = power(x, n / 2);
    return temp * temp;
}
```

---

## 3. Greedy Algorithm

### Design Idea
Make locally optimal choice at each step with hope of finding global optimum. Works when problem has **greedy choice property** and **optimal substructure**.

### Complexity Analysis
- **Max Subset Product**: O(n) time, O(1) space

### Comparison with Higher Complexity Approach
| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Greedy (Max Subset Product) | O(n) | O(1) | Very fast, optimal for this problem | Not universally applicable |
| Brute Force (All Subsets) | O(2^n) | O(n) | Always correct | Exponential, impractical for n > 30 |

### Code Example
```cpp
// From Greedy-sample.cpp - Greedy Max Subset Product
int GreedyMaxSubsetProduct() {
    if (n == 1) return a[0];

    int cntZero = 0, cntNegative = 0;
    int product = 1, maxNegative = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (!a[i]) cntZero++;
        else {
            product *= a[i];
            if (a[i] < 0) {
                cntNegative++;
                maxNegative = max(maxNegative, a[i]);
            }
        }
    }

    if ((cntZero == n) || (cntNegative == 1 && cntZero == n-1)) return 0;
    if (cntNegative & 1) product /= maxNegative;
    return product;
}
```

---

## 4. Dynamic Programming

### Design Idea
Solve by breaking into overlapping subproblems, storing results to avoid recomputation. Two approaches: **Memoization** (top-down) and **Tabulation** (bottom-up).

### Complexity Analysis
- **Fibonacci**: O(n) time, O(n) space (can be O(1) with rolling array)

### Comparison with Higher Complexity Approach
| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| DP (Tabulation) | O(n) | O(n) | Optimal, no redundant work | Uses extra space |
| DP (Memoization) | O(n) | O(n) | Easy to implement from recursion | Stack overhead |
| Naive Recursion | O(2^n) | O(n) | Simple code | Exponential time |

### Code Example
```cpp
// From DP-sample.cpp - Fibonacci (Tabulation)
void GenerateFibo() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
```

---

## Summary

| Paradigm | Best For | Key Insight |
|----------|----------|-------------|
| Brute Force | Small n, simple problems | Try everything |
| Divide & Conquer | Problems divisible into independent subproblems | Reduce problem size logarithmically |
| Greedy | Problems with optimal substructure + greedy choice | Local optimum → global optimum |
| Dynamic Programming | Overlapping subproblems, optimal substructure | Trade space for time |