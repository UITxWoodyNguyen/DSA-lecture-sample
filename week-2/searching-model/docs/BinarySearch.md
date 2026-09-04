# Binary Search Algorithm

## Overview
Binary Search (Tìm kiếm nhị phân) là thuật toán tìm kiếm hiệu quả trên mảng **đã được sắp xếp**. Áp dụng chiến lược **Chia để trị (Divide and Conquer)**: giảm một nửa không gian tìm kiếm sau mỗi bước so sánh.

---

## 1. Ý tưởng thiết kế

### Điều kiện bắt buộc
- **Mảng phải được sắp xếp** (tăng dần hoặc giảm dần)
- Phần tử có thể so sánh được (hỗ trợ `<`, `>`, `==`)
- Truy cập ngẫu nhiên O(1) (mảng, vector - không dùng cho linked list)

### Ý tưởng cốt lõi
1. So sánh target với phần tử giữa mảng (`mid`)
2. Nếu bằng → tìm thấy
3. Nếu target > arr[mid] → tìm ở nửa sau (bỏ nửa trước)
4. Nếu target < arr[mid] → tìm ở nửa trước (bỏ nửa sau)
5. Lặp lại cho đến khi tìm thấy hoặc khoảng tìm kiếm rỗng

---

## 2. Phân tích các phiên bản

### Phiên bản 1: Iterative (Vòng lặp)
```cpp
int BinarySearch(int arr[], int size, int target) {
    int lo = 0, hi = size - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;  // Tránh tràn số: lo + (hi - lo) / 2
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```
- **Độ phức tạp:** O(log n) time, O(1) space
- **Ưu điểm:** Không dùng stack, tiết bộ nhớ, nhanh hơn đệ quy

### Phiên bản 2: Recursive (Đệ quy)
```cpp
int RecursionBinarySearch(int arr[], int lo, int hi, int target) {
    if (lo > hi) return -1;
    int mid = (lo + hi) >> 1;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return RecursionBinarySearch(arr, mid + 1, hi, target);
    else return RecursionBinarySearch(arr, lo, mid - 1, target);
}
```
- **Độ phức tạp:** O(log n) time, O(log n) space (call stack)
- **Nhược điểm:** Gây stack overflow nếu n quá lớn, chậm hơn do overhead gọi hàm

---

## 3. Phân tích độ phức tạp

| Metric | Iterative | Recursive |
|--------|-----------|-----------|
| **Time Complexity** | O(log n) | O(log n) |
| **Space Complexity** | O(1) | O(log n) |
| **Best Case** | O(1) - target ở mid | O(1) |
| **Worst Case** | O(log n) | O(log n) |
| **Average Case** | O(log n) | O(log n) |

### Tại sao O(log n)?
Mỗi bước loại bỏ nửa dữ liệu: n → n/2 → n/4 → ... → 1
Số bước: log₂(n)

---

## 4. So sánh với Linear Search

| Tiêu chí | Linear Search | Binary Search |
|----------|---------------|---------------|
| **Điều kiện mảng** | Bất kỳ (có/không sắp xếp) | **Bắt buộc sắp xếp** |
| **Time Complexity** | O(n) | **O(log n)** |
| **Space Complexity** | O(1) | O(1) iterative / O(log n) recursive |
| **Truy cập dữ liệu** | Sequential (cache-friendly) | Random access |
| **Triển khai** | Đơn giản | Phức tạp hơn (xử lý biên, tràn số) |
| **Thao tác trên mảng** | Không sửa mảng | Không sửa mảng |

### Khi nào Binary Search tốt hơn?
- n lớn (n > 50-100)
- Tìm kiếm nhiều lần trên cùng mảng (sort một lần, search nhiều lần)
- Mảng tĩnh, ít insert/delete

### Khi nào Linear Search tốt hơn?
- n nhỏ
- Mảng không sắp xếp và không muốn sort (O(n log n))
- Chỉ tìm kiếm một lần
- Linked list (không có random access)

---

## 5. Các biến thể quan trọng

### Lower Bound (first ≥ target)
```cpp
int lowerBound(int arr[], int size, int target) {
    int lo = 0, hi = size;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo; // Vị trí đầu tiên ≥ target
}
```

### Upper Bound (first > target)
```cpp
int upperBound(int arr[], int size, int target) {
    int lo = 0, hi = size;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (arr[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo; // Vị trí đầu tiên > target
}
```

### Tìm vị trí chèn (Insert Position)
```cpp
int searchInsert(int arr[], int size, int target) {
    return lowerBound(arr, size, target);
}
```

### Tìm first/last occurrence (mảng có phần tử trùng)
```cpp
int firstOccurrence(int arr[], int size, int target) {
    int lo = 0, hi = size - 1, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (arr[mid] == target) {
            ans = mid;
            hi = mid - 1; // Tiếp tục tìm bên trái
        } else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return ans;
}
```

---

## 6. Các lỗi thường gặp & Cách tránh

### Tràn số khi tính mid
```cpp
// ❌ Sai: có thể tràn khi lo + hi > INT_MAX
int mid = (lo + hi) / 2;

// ✅ Đúng: tránh tràn số
int mid = lo + (hi - lo) / 2;
// Hoặc dùng bit shift (chỉ đúng cho số dương)
int mid = (lo + hi) >> 1;
```

### Điều kiện vòng lặp
```cpp
// Tìm exact match: lo <= hi
while (lo <= hi) { ... }

// Lower/Upper bound: lo < hi
while (lo < hi) { ... }
```

### Cập nhật biên
```cpp
// ✅ Đúng khi arr[mid] < target
lo = mid + 1;  // Không bao gồm mid

// ✅ Đúng khi arr[mid] > target
hi = mid - 1;  // Không bao gồm mid

// ❌ Sai: lo = mid hoặc hi = mid có thể gây loop vô tận
```

---

## 7. Ứng dụng mở rộng

| Bài toán | Ý tưởng |
|----------|---------|
| Tìm căn bậc 2 nguyên | Binary search trên [0, n] |
| Tìm giá trị lớn nhất thỏa mãn điều kiện | Binary search trên đáp án (Parametric Search) |
| Tìm peak element | So sánh mid với neighbor |
| Search in rotated sorted array | Xác định nửa nào sorted, target có ở đó không |
| Median of two sorted arrays | Binary search partition |
| Aggressive cows / Painters partition | Binary search trên kết quả (min max distance) |

---

## 8. Tóm tắt

| Đặc điểm | Mô tả |
|----------|-------|
| **Paradigm** | Divide and Conquer |
| **Điều kiện** | Mảng đã sắp xếp, random access |
| **Time** | O(log n) |
| **Space** | O(1) iterative, O(log n) recursive |
| **Ưu điểm** | Nhanh hơn Linear Search lớn r magnituder |
| **Nhược điểm** | Cần sort trước, phức tạp triển khai đúng |

**Best Practice:** Dùng iterative version cho production code. Dùng `std::binary_search`, `std::lower_bound`, `std::upper_bound` trong C++ STL.