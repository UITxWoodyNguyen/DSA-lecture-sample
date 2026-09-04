# Interpolation Search Algorithm (Tìm kiếm nội suy)

## Overview
Interpolation Search là cải tiến của Binary Search. Thay vì luôn chia đôi mảng tại giữa (`mid = (lo + hi) / 2`), nó **dự đoán vị trí** của target dựa trên phân bố giá trị, giả định dữ liệu **phân bố đều (uniformly distributed)**.

---

## 1. Ý tưởng thiết kế

### Điều kiện bắt buộc
- **Mảng phải được sắp xếp** (tăng dần)
- **Phân bố dữ liệu đồng đều** (uniform distribution) - đây là điều kiện quan trọng nhất
- Phần tử là kiểu số (int, float, double) để tính toán nội suy
- Không có phần tử trùng lặp quá nhiều (hoặc cần xử lý riêng)

### Công thức nội suy (Linear Interpolation)
Giả định các điểm dữ liệu nằm trên đường thẳng. Từ hai điểm đã biết `(lo, arr[lo])` và `(hi, arr[hi])`, tìm `mid` sao cho `arr[mid] ≈ target`:

```
mid = lo + ((hi - lo) * (target - arr[lo])) / (arr[hi] - arr[lo])
```

**Ý nghĩa:** Tỷ lệ khoảng cách index = Tỷ lệ khoảng cách giá trị.

### Ví dụ minh họa
Mảng: `[10, 20, 30, 40, 50, 60, 70, 80, 90, 100]`, target = 70
- Binary Search: mid = 4 → arr[4]=50 → mid = 7 → arr[7]=80 → mid = 6 → **tìm thấy** (3 bước)
- Interpolation: mid = 0 + (9 * 60) / 90 = 6 → arr[6]=70 → **tìm thấy ngay** (1 bước)

---

## 2. Phân tích các phiên bản

### Phiên bản 1: Iterative
```cpp
int InterpolationSearch(int arr[], int size, int target) {
    int lo = 0, hi = size - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) * (target - arr[lo])) / (arr[hi] - arr[lo]);
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

### Phiên bản 2: Recursive
```cpp
int RecursionInterpolationSearch(int arr[], int lo, int hi, int target) {
    if (lo > hi) return -1;
    int mid = lo + ((hi - lo) * (target - arr[lo])) / (arr[hi] - arr[lo]);
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return RecursionInterpolationSearch(arr, mid + 1, hi, target);
    else return RecursionInterpolationSearch(arr, lo, mid - 1, target);
}
```

---

## 3. Phân tích độ phức tạp

| Trường hợp | Time Complexity | Space Complexity |
|------------|-----------------|------------------|
| **Best Case** | O(1) - đoán trúng ngay | O(1) / O(log n) |
| **Average Case (Uniform)** | **O(log(n))** | O(1) / O(log n) |
| **Worst Case** | O(n) | O(1) / O(log n) |

### Tại sao O(log(n)) khi uniform?
Mỗi bước giảm kích thước tìm kiếm theo cấp số nhân: n → √n → √(√n) → ...
Số bước: log₂(log₂(n))

### Khi nào bị O(n)?
- Phân bố **không đồng đều** (skewed distribution)
- Ví dụ: `[1, 2, 3, 4, 5, 6, 7, 8, 9, 1000000]`, target = 9
  - mid ≈ 0 + (9 * 8) / 999999 ≈ 0 → chỉ tăng 1 mỗi lần → O(n)
- Tất cả phần tử giống nhau (arr[hi] == arr[lo]) → chia cho 0

---

## 4. So sánh với Linear Search & Binary Search

| Tiêu chí | Linear Search | Binary Search | Interpolation Search |
|----------|---------------|---------------|---------------------|
| **Điều kiện mảng** | Bất kỳ | **Đã sắp xếp** | **Đã sắp xếp + Phân bố đều** |
| **Kiểu dữ liệu** | Bất kỳ (so sánh ==) | Có thứ tự (<, >) | **Số học (cần -, *, /)** |
| **Best Case** | O(1) | O(1) | **O(1)** |
| **Average Case** | O(n) | O(log n) | **O(log(n))** |
| **Worst Case** | O(n) | O(log n) | **O(n)** |
| **Space (Iterative)** | O(1) | O(1) | O(1) |
| **Truy cập bộ nhớ** | Sequential (cache tốt) | Random | Random |
| **Độ phức tạp code** | Thấp | Trung bình | Trung bình |

### Ưu điểm so với Binary Search
- **Nhanh hơn đáng kể** khi dữ liệu phân bố đều: O(log(n)) vs O(log n)
- Với n = 1 tỷ: log₂(n) ≈ 30, log₂(log₂(n)) ≈ 5 → **6x ít phép so sánh**

### Nhược điểm so với Binary Search
- **Worst case O(n)** - rất tệ khi phân bố lệch
- **Chỉ dùng cho số** - không áp dụng cho string, struct tùy chỉnh
- Cần kiểm tra `arr[hi] != arr[lo]` tránh chia cho 0
- Phép tính `mid` tốn hơn so với `(lo + hi) >> 1`

---

## 5. Các cải tiến và biến thể

### Xử lý chia cho 0 (phần tử trùng)
```cpp
int InterpolationSearchSafe(int arr[], int size, int target) {
    int lo = 0, hi = size - 1;
    while (lo <= hi && target >= arr[lo] && target <= arr[hi]) {
        if (arr[lo] == arr[hi]) {  // Tất cả phần tử giống nhau
            return (arr[lo] == target) ? lo : -1;
        }
        int mid = lo + ((hi - lo) * (target - arr[lo])) / (arr[hi] - arr[lo]);
        if (mid < lo || mid > hi) mid = lo;  // Clamp phòng overflow
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

### Interpolation Search trên phân bố không đều (Adaptive)
```cpp
// Kết hợp với Binary Search: nếu tiến độ chậm, chuyển sang Binary
int HybridSearch(int arr[], int size, int target) {
    int lo = 0, hi = size - 1;
    int steps = 0;
    while (lo <= hi) {
        if (++steps > 20) {  // Quá nhiều bước → chuyển Binary
            return BinarySearch(arr + lo, hi - lo + 1, target) + lo;
        }
        if (arr[lo] == arr[hi]) return (arr[lo] == target) ? lo : -1;
        int mid = lo + ((hi - lo) * (target - arr[lo])) / (arr[hi] - arr[lo]);
        mid = max(lo, min(hi, mid));  // Clamp
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

---

## 6. Khi nào nên dùng Interpolation Search?

| Tình huống | Khuyến nghị |
|------------|-------------|
| Dữ liệu số, phân bố đều (uniform) | ✅ **Tốt nhất** |
| Dữ liệu số, phân bố chuẩn (normal) | ✅ Vẫn tốt |
| Dữ liệu số, phân bố lệch (exponential, power law) | ❌ Dùng Binary Search |
| Dữ liệu không phải số (string, object) | ❌ Không áp dụng được |
| Cần worst-case guarantee O(log n) | ❌ Dùng Binary Search |
| Mảng nhỏ (n < 1000) | ❌ Binary Search đủ nhanh, đơn giản hơn |
| Database index (B-tree) | ❌ Dùng B-tree / Binary Search |

---

## 7. Ứng dụng thực tế

| Lĩnh vực | Ứng dụng |
|----------|----------|
| Database | Index trên cột số phân bố đều (timestamp, ID tự tăng) |
| File system | Tìm kiếm trong file dữ liệu đã sort |
| Scientific computing | Tìm giá trị trong bảng tra (lookup table) |
| Game dev | Tìm frame trong animation timeline |
| Network | Routing table lookup |

---

## 8. Tóm tắt

| Đặc điểm | Mô tả |
|----------|-------|
| **Paradigm** | Decrease and Conquer (giảm kích thước không đều) |
| **Điều kiện** | Sorted + Uniform distribution + Numeric |
| **Best Time** | O(1) |
| **Average Time** | O(log(n)) |
| **Worst Time** | O(n) |
| **Space** | O(1) iterative, O(log n) recursive |

**Kết luận:** Interpolation Search là "siêu nhân" khi dữ liệu phân bố đều (O(log(n))), nhưng "kẻ thua cuộc" khi phân bố lệch (O(n)). Trong thực tế, **Binary Search an toàn và tin cậy hơn**, Interpolation Search chỉ dùng khi chắc chắn phân bố uniform và cần tối đa hiệu năng.

**Best Practice:** Dùng Hybrid approach - thử Interpolation vài bước, nếu không hiệu quả chuyển sang Binary Search.