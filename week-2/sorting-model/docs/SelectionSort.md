# Selection Sort - Sắp xếp chọn trực tiếp

## Method

**Phân tích**: Giả sử có danh sách `A` đã được sắp xếp theo thứ tự $R$. Khi đó:
- `A[0]` là phần tử nhỏ nhất trong `A[]`
- `A[1]` là phần tử nhỏ nhất trong `A[] \ {A[0]}`
- `A[2]` là phần tử nhỏ nhất trong `A[] \ {A[0], A[1]}`

**Kết luận**: Với danh sách đã có thứ tự $R$, `A[i]` là phần tử nhỏ thứ `i`

**Ý tưởng triển khai**: Chọn phần tử nhỏ thứ `i` theo thứ tự $R$ trong danh sách `A` và đặt vào vị trí `i` của danh sách

**Mã giả**:
```
i = 0   // Starting index: i = 0
while i < n:
    min = i     // Init minimum index to find the i-th min value of R
    j = i+1     // Starting to find the i-th value of A with R-order by starting brute force from index i+1
    while j < n:
        if A[j] R A[min]: min = j
        j = j + 1
    
    // 2 cases can be available here: A value which is R than A[i] available in A[], try replace A[i] by A[min]. In contrast, A[i] is the i-th value of R, so min's value will not be changed
    swap(A[i], A[min])      
    i++
```

## Code

Selection Sort using `while` loops:
```c++
void selectionSort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        int minIdx = i, j = i + 1;
        while (j < n) {
            if (arr[j] < arr[minIdx]) minIdx = j;
            j++;
        }

        swap(arr[i], arr[minIdx]);
        i++;
    }
}
```

Selection Sort using `for` loops:
```c++
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}
```

---

## Đánh giá thuật toán

### 1. Phân tích độ phức tạp

| Trường hợp | Time Complexity | Giải thích |
|------------|-----------------|------------|
| **Best Case** | O(n²) | Mảng đã sort: vẫn phải duyệt toàn bộ để tìm min |
| **Average Case** | O(n²) | ~ n²/2 so sánh, n swap |
| **Worst Case** | O(n²) | Mảng giảm dần: vẫn n²/2 so sánh, n swap |

**Chi tiết:**
- Số phép so sánh: (n-1) + (n-2) + ... + 1 = n(n-1)/2 = **O(n²)**
- Số phép swap: đúng **n** lần (mỗi vòng lặp ngoài swap 1 lần)
- Không phụ thuộc vào thứ tự ban đầu của dữ liệu

### 2. Phân tích không gian bộ nhớ

| Metric | Value | Giải thích |
|--------|-------|------------|
| **Space Complexity** | **O(1)** | In-place sorting, chỉ dùng biến tạm `minIdx`, `i`, `j` |
| **Auxiliary Space** | O(1) | Không cần mảng phụ, không dùng đệ quy |
| **Stable** | **Không** | Swap có thể đổi thứ tự phần tử bằng nhau |

### 3. Ưu điểm

| Ưu điểm | Mô tả |
|---------|-------|
| **Đơn giản, dễ hiểu** | Logic trực quan: tìm min → đưa về đầu |
| **Số swap tối thiểu** | Chỉ **n swap** - ít nhất trong các thuật toán comparison-based |
| **In-place** | O(1) extra memory - phù hợp hệ thống nhúng, bộ nhớ hạn chế |
| **Không phụ thuộc dữ liệu** | Time complexity luôn O(n²) dù best/average/worst |
| **Tốt cho ghi dữ liệu đắt** | Khi ghi vào bộ nhớ (flash, EEPROM) tốn kém, ít swap là lợi thế |
| **Dễ triển khai** | Code ngắn, ít bug tiềm ẩn |

### 4. Nhược điểm

| Nhược điểm | Mô tả |
|------------|-------|
| **Time O(n²)** | Chậm với n lớn, không phù hợp big data |
| **Không stable** | Thứ tự phần tử bằng nhau có thể bị đảo |
| **Không adaptive** | Không tận dụng mảng gần-sorted |
| **Cache performance kém** | Truy cập nhảy nhổn nhêtre không tuần tự |
| **Không song song hóa dễ** | Phụ thuộc tuần tự giữa các vòng lặp |

### 5. Kích thước bài toán phù hợp (Problem Size)

| Kích thước n | Khuyến nghị | Lý do |
|--------------|-------------|-------|
| **n ≤ 50** | ✅ **Rất phù hợp** | Nhanh đủ, code đơn giản, overhead thấp |
| **50 < n ≤ 500** | ⚠️ **Chấp nhận được** | Vẫn chạy trong < 1ms trên CPU hiện đại |
| **500 < n ≤ 5000** | ❌ **Không khuyến nghị** | Insertion Sort tốt hơn (adaptive, cache-friendly) |
| **n > 5000** | ❌ **Tuyệt đối tránh** | O(n²) quá chậm, dùng Merge/Quick/Heap Sort |

**Quy tắc thực tế:** Nếu n < 50-100 và không sort thường xuyên → Selection Sort OK. Còn lại → dùng thuật toán O(n log n).

### 6. So sánh với các thuật toán O(n²) khác

| Thuật toán | Time (Avg) | Swaps | Stable | Adaptive | Cache | Khi nào dùng |
|------------|------------|-------|--------|----------|-------|--------------|
| **Selection Sort** | O(n²) | **n** (min) | ❌ | ❌ | Kém | n nhỏ, ghi bộ nhớ đắt |
| **Insertion Sort** | O(n²) | O(n²) | ✅ | ✅ | Tốt | n nhỏ, gần-sorted, online |
| **Bubble Sort** | O(n²) | O(n²) | ✅ | ✅ (với flag) | Trung bình | Giáo dục, n rất nhỏ |

### 7. So sánh với thuật toán O(n log n)

| Thuật toán | Time | Space | Stable | Khi nào dùng |
|------------|------|-------|--------|--------------|
| **Selection Sort** | O(n²) | O(1) | ❌ | n ≤ 50 |
| **Merge Sort** | O(n log n) | O(n) | ✅ | Cần stable, linked list |
| **Quick Sort** | O(n log n)* | O(log n) | ❌ | General purpose, in-place |
| **Heap Sort** | O(n log n) | O(1) | ❌ | Cần O(1) space + O(n log n) worst-case |
| **Tim Sort** | O(n log n) | O(n) | ✅ | Thực tế (Python, Java, C++ STL) |

*Quick Sort worst-case O(n²) nhưng rare với pivot tốt.

### 8. Các biến thể cải tiến

**Bidirectional Selection Sort (Cocktail Selection Sort):**
- Tìm cả min và max trong một pass
- Giảm số pass từ n → n/2
- Vẫn O(n²) nhưng nhanh gấp ~2 lần hằng số

**Heap Sort (cải tiến triết lý Selection Sort):**
- Dùng heap để tìm min trong O(log n) thay vì O(n)
- Time: O(n log n), Space: O(1)
- Đây là Selection Sort "thông minh hóa"

### 9. Ứng dụng thực tế

| Lĩnh vực | Ứng dụng |
|----------|----------|
| **Embedded systems** | Sắp xếp mảng config nhỏ, bộ nhớ hạn chế |
| **Flash/EEPROM** | Ít nhất write cycles (chỉ n swap) |
| **Giáo dục** | Minh họa O(n²), in-place, unstable |
| **Hybrid algorithms** | Base case cho Quick Sort / Merge Sort khi n ≤ 10-20 |
| **Selection problem** | Tìm k-th smallest (partial selection sort: O(kn)) |

### 10. Tóm tắt

| Đặc điểm | Giá trị |
|----------|---------|
| **Paradigm** | Decrease and Conquer / Brute Force |
| **Time (All cases)** | O(n²) |
| **Space** | O(1) - In-place |
| **Stable** | No |
| **Adaptive** | No |
| **Swaps** | n (tối thiểu) |
| **Comparisons** | n(n-1)/2 |
| **Best for** | n ≤ 50, memory-constrained, minimal writes |

**Kết luận:** Selection Sort là thuật toán "đơn giản nhưng không hiệu quả" cho n lớn. Giá trị chính: **giáo dục**, **hệ thống nhúng có bộ nhớ cực hạn**, và **tối thiểu hóa ghi bộ nhớ**. Trong production thực tế, thay bằng Insertion Sort (n nhỏ) hoặc Quick/Merge/Tim Sort (n lớn).