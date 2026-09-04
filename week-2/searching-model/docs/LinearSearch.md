# Linear Search Algorithm

## Overview
Linear Search (Tìm kiếm tuyến tính) là thuật toán tìm kiếm đơn giản nhất: duyệt qua từng phần tử của mảng từ đầu đến cuối cho đến khi tìm thấy giá trị mục tiêu hoặc hết mảng.

---

## 1. Ý tưởng thiết kế

### Ý tưởng ban đầu (Version 1 & 2)
- Duyệt qua mảng từ chỉ số 0 đến size-1
- So sánh từng phần tử với target
- Nếu tìm thấy → trả về chỉ số
- Nếu hết mảng không thấy → trả về -1

**Điều kiện áp dụng:** Mảng **không cần được sắp xếp**. Hoạt động với mọi loại dữ liệu có thể so sánh bằng (==, !=).

---

## 2. Phân tích các phiên bản

### Version 1: Vòng lặp FOR
```cpp
int LinearSearchV1(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```
- **Độ phức tạp:** O(n) time, O(1) space
- **Đặc điểm:** Code rõ ràng, dễ đọc, chuẩn C++

### Version 2: Vòng lặp WHILE
```cpp
int LinearSearchV2(int arr[], int size, int target) {
    int i = 0;
    while (i < size) {
        if (arr[i] == target) return i;
        i++;
    }
    return -1;
}
```
- **Độ phức tạp:** O(n) time, O(1) space
- **Đặc điểm:** Tương đương V1, chỉ khác cú pháp vòng lặp

### Version 3: Cải tiến (Sentinel Linear Search)
```cpp
int LinearSearchV3(int arr[], int size, int target) {
    int i = 0;
    arr[size] = target;  // Gán sentinel tại vị trí size
    while (arr[i] != target) i++;

    if (i == size) return -1;
    return i;
}
```
- **Độ phức tạp:** O(n) time, O(1) space
- **Ý tưởng:** Loại bỏ kiểm tra biên `i < size` trong vòng lặp bằng cách đặt **sentinel** (giá trị canh) tại `arr[size] = target`
- **Yêu cầu:** Mảng phải có **khoảng trống ít nhất 1 phần tử** sau phần tử cuối (size+1 phần tử)

---

## 3. So sánh và Phân tích cải tiến

| Tiêu chí | V1/V2 (Cơ bản) | V3 (Sentinel) |
|----------|----------------|---------------|
| **Số lần so sánh/lặp** | 2 phép so sánh/lần lặp: `i < size` và `arr[i] == target` | 1 phép so sánh/lần lặp: `arr[i] != target` |
| **Độ phức tạp thời gian** | O(n) | O(n) |
| **Hằng số (constant factor)** | Lớn hơn | Nhỏ hơn (~2x nhanh hơn về lý thuyết) |
| **Điều kiện mảng** | Bất kỳ mảng size phần tử | Cần mảng có size+1 phần tử |
| **An toàn** | An toàn, không sửa mảng | **Sửa đổi mảng gốc** (gán arr[size]) |
| **Độ phức tạp không gian** | O(1) | O(1) |

### Phân tích chi tiết cải tiến

**Ưu điểm của Sentinel (V3):**
- Giảm một phép so sánh trong vòng lặp → nhanh hơn trong thực tế
- Code gọn nhẹ hơn
- Hữu ích khi tìm kiếm trong vòng lặp lồng nhau hoặc gọi nhiều lần

**Nhược điểm của Sentinel (V3):**
- **Phá vỡ tính bất biến của mảng** - gán giá trị vào `arr[size]`
- Không dùng được cho mảng `const` hoặc mảng chỉ đọc
- Cần đảm bảo bộ nhớ tại `arr[size]` có thể ghi được (không gây buffer overflow)
- Không thread-safe do sửa đổi dữ liệu chung
- Chỉ tối ưu hằng số, không thay đổi độ phức tạp Big-O

---

## 4. Khi nào nên dùng Linear Search?

| Trường hợp | Khuyến nghị |
|------------|-------------|
| Mảng nhỏ (n < 50) | ✅ Linear Search đủ tốt |
| Mảng không sắp xếp | ✅ Linear Search là lựa chọn duy nhất |
| Tìm kiếm một lần (single query) | ✅ Không cần sort trước |
| Tìm kiếm nhiều lần trên cùng mảng | ❌ Nên sort + Binary Search O(log n) |
| Mảng lớn, cần hiệu năng cao | ❌ Dùng Hash Table O(1) hoặc Binary Search |

---

## 5. Mở rộng

### Tìm kiếm tuyến tính cho nhiều kết quả
```cpp
void LinearSearchAll(int arr[], int size, int target, vector<int>& result) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) result.push_back(i);
    }
}
```

### Tìm kiếm tuyến tính với predicate (generic)
```cpp
template <typename T, typename Predicate>
int LinearSearchIf(T arr[], int size, Predicate pred) {
    for (int i = 0; i < size; i++) {
        if (pred(arr[i])) return i;
    }
    return -1;
}
```

---

## Tóm tắt

| Phiên bản | Ưu điểm | Nhược điểm | Khi nào dùng |
|-----------|---------|------------|--------------|
| V1 (for) | Đơn giản, an toàn, chuẩn | 2 so sánh/lặp | Mặc định, code production |
| V2 (while) | Tương tự V1 | Tương tự V1 | Theo sở thích coding style |
| V3 (sentinel) | Nhanh hơn ~2x hằng số | Sửa mảng, không an toàn | Competitive programming, mảng cục bộ, hiệu năng cực đại |

**Kết luận:** V1/V2 nên dùng trong production code. V3 chỉ dùng khi hiểu rõ trade-off và môi trường cho phép sửa mảng.