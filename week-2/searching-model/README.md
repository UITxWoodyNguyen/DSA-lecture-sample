# Searching Algorithms Model

Mô phỏng và so sánh các thuật toán tìm kiếm cơ bản trong DSA.

## Cấu trúc thư mục

```
searching-model/
├── LinearSearchModel.cpp      # Linear Search (3 versions)
├── BinarySearchModel.cpp      # Binary Search (iterative + recursive)
├── InterpolationSearchModel.cpp # Interpolation Search (iterative + recursive)
├── LinearSearch.md            # Chi tiết Linear Search
├── BinarySearch.md            # Chi tiết Binary Search
├── InterpolationSearch.md     # Chi tiết Interpolation Search
└── README.md                  # File này
```

---

## Tóm tắt 3 thuật toán

| Thuật toán | Điều kiện | Time (Avg) | Time (Worst) | Space | Độ phức tạp code |
|------------|-----------|------------|--------------|-------|------------------|
| **Linear Search** | Không cần sort | O(n) | O(n) | O(1) | ⭐ Rất dễ |
| **Binary Search** | **Đã sort**, random access | O(log n) | O(log n) | O(1) | ⭐⭐ Trung bình |
| **Interpolation Search** | **Đã sort + Uniform + Numeric** | **O(log log n)** | O(n) | O(1) | ⭐⭐ Trung bình |

---

## Khi nào dùng thuật toán nào?

```
Cần tìm kiếm?
│
├─ Mảng KHÔNG sắp xếp?
│   └─ → Linear Search (hoặc Hash Table O(1) nếu tìm nhiều lần)
│
└─ Mảng ĐÃ sắp xếp?
    │
    ├─ Kiểu dữ liệu KHÔNG phải số (string, struct)?
    │   └─ → Binary Search
    │
    ├─ Số lượng phần tử nhỏ (n < 1000)?
    │   └─ → Binary Search (đủ nhanh, an toàn)
    │
    ├─ Dữ liệu số, phân bố ĐỀU (uniform)?
    │   └─ → Interpolation Search (nhanh nhất O(log log n))
    │
    ├─ Dữ liệu số, phân bố LỆCH (skewed)?
    │   └─ → Binary Search (worst-case O(log n) đảm bảo)
    │
    └─ Cần worst-case guarantee?
        └─ → Binary Search
```

---

## So sánh hiệu năng thực tế (ước lượng)

| n | Linear Search | Binary Search | Interpolation Search (uniform) |
|---|---------------|---------------|--------------------------------|
| 10³ | 1,000 | 10 | ~3 |
| 10⁶ | 1,000,000 | 20 | ~4 |
| 10⁹ | 1,000,000,000 | 30 | ~5 |
| 10¹² | 10¹² | 40 | ~6 |

*Interpolation Search chỉ đạt O(log log n) khi dữ liệu phân bố đều. Nếu lệch → O(n) tệ hơn Linear Search.*

---

## Biên dịch và chạy

```bash
# Linear Search
g++ LinearSearchModel.cpp -o linear
./linear

# Binary Search
g++ BinarySearchModel.cpp -o binary
./binary

# Interpolation Search
g++ InterpolationSearchModel.cpp -o interpolation
./interpolation
```

---

## Tài liệu tham khảo chi tiết

- [Linear Search](./LinearSearch.md) - 3 phiên bản: for, while, sentinel
- [Binary Search](./BinarySearch.md) - Iterative, recursive, lower/upper bound, variants
- [Interpolation Search](./InterpolationSearch.md) - Công thức nội suy, hybrid approach, edge cases

---

## Bài học chính

1. **Linear Search** - Cơ bản, luôn đúng, chậm. Dùng khi n nhỏ hoặc mảng không sort.
2. **Binary Search** - Chuẩn mực cho mảng sort. O(log n) đảm bảo, an toàn, phổ biến.
3. **Interpolation Search** - Tối ưu cho dữ liệu uniform. Nhanh hơn Binary Search nhưng rủi ro O(n) worst-case.

**Best Practice trong thực tế:** Dùng `std::binary_search` / `std::lower_bound` / `std::upper_bound` từ STL. Tự implement chỉ khi học thuật hoặc competitive programming.