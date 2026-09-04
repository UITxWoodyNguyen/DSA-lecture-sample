# Custom Vector Implementation (c_vector)

Minimal STL-like vector implementation with commonly used functions.

## Features
- Dynamic array with automatic resizing (2x capacity)
- Copy constructor and copy assignment
- Move semantics not included (kept simple)
- Common operations: push_back, pop_back, insert, erase, clear, swap
- Iterator support: begin(), end()
- Random access: operator[]
- Size/capacity queries

## Files
- `c_vector.hpp` - Header with class declaration
- `c_vector.cpp` - Implementation (explicitly instantiated for int, double, char, string)
- `demo.cpp` - Usage examples

## Usage
```cpp
#include "c_vector.hpp"

c_vector<int> v;
v.push_back(1);
v.push_back(2);
v.insert(1, 10);  // [1, 10, 2]
v.erase(0);       // [10, 2]
v.pop_back();     // [10]
```

## Compile
```bash
g++ demo.cpp c_vector.cpp -o demo
./demo
```

## Complexity
| Operation | Time |
|-----------|------|
| push_back | Amortized O(1) |
| pop_back | O(1) |
| insert/erase | O(n) |
| operator[] | O(1) |
| size/capacity/empty | O(1) |