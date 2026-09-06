# Insertion Sort - Sắp xếp chèn

## Method

**Phân tích**: Giả sử `A[] = {A[0], A[1], ..., A[n-1]}` đã được sắp xếp theo thứ tự $R$. Khi đó, để `A[]` có `n+1` phần tử mà vẫn giữ nguyên thứ tự $R$, ta cần tìm vị trí `k` để chèn phần tử `A[n]` sao cho với mọi `i < k`, `A[i] R A[n]` (Tức với mọi `i` trong khoảng `[0..k-1]`, dãy `A[0], A[1], ..., A[k-1], A[n]` có thứ tự $R$)

**Ý tưởng**:
- **Bài toán đơn giản nhất**: `A[0]` có `size = 1` - chỉ có 1 phần tử. Khi đó `A[] = {A[0]}` đã có thứ tự $R$.
- **Step 1**: Với mọi vị trí `i > 0`, thực hiện tìm kiếm trong đoạn `[0...i-1]` để tìm vị trí `k` lớn nhất sao cho `A[k] R A[i]` (Tức tìm kiếm vị trí `k` gần `i` nhất thỏa mãn điều kiện trên)
- **Step 2**: Đẩy tất cả các phần tử trong khoảng `[k+1...n-1]` sang phải 1 vị trí - Tức gán giá trị của `A[i]` cho `A[i+1]`.
- **Step 3**: Gán giá trị của `A[i]` cho `A[k+1]`, giá trị của `A[i-1]` cho `A[i]`

**Nhận xét**: 
- Với mỗi vị trí `k` trong khoảng `[0...i-1]` không thỏa thứ tự $R$ (`!(A[k] R A[i])`), ta có thể thực hiện đẩy giá trị của `A[k]` sang phải (tức `A[k+1] = A[k]`) mà không làm ảnh hưởng tới quá trình tìm kiếm. 
- Khi thực hiện đồng thời thao tác này, việc gán `A[i] = A[i-1]` ở bước 3 đã được thực hiện trong vòng lặp đầu tiên (`k = i-1` và không thỏa $R$), do đó chỉ cần gán `A[k+1] = A[i]` sau khi kết thúc vòng lặp

**Mã giả**
```
i = 1   // Starting index with condition "i > 0" --> i = 1
while i < n:
    key = A[i]
    k = i - 1
    while (k >= 0) and (!(A[k] R A[i])):
        A[k+1] = A[k]
        k--
    A[k+1] = key   // A[k+1] = A[i]
    i++
```

---

## Code

**Insertion Sort using WHILE loops:**
```cpp
void InsertionSort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        int key = arr[i];
        int nearest = i - 1;
        while (nearest >= 0 && arr[nearest] > key) {
            arr[nearest + 1] = arr[nearest];
            nearest--;
        }
        arr[nearest + 1] = key;
        i++;
    }
}
```

**Insertion Sort using FOR loops:**
```cpp
void InsertionSortFor(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int nearest;
        for(nearest = i-1; nearest >= 0; nearest--) {
            if (arr[nearest] < key) break;
            arr[nearest + 1] = arr[nearest];
        }
        arr[nearest + 1] = key;
    }
}
```

**Insertion Sort Recursive:**
```cpp
void InsertionSortRecursive(int arr[], int n) {
    if (n < 2) return;
    InsertionSortRecursive(arr, n - 1);

    int key = arr[n-1];
    int nearest = n - 2;
    while (nearest >= 0 && arr[nearest] > key) {
        arr[nearest + 1] = arr[nearest];
        nearest--;
    }
    arr[nearest + 1] = key;
}
```

---

## Step-by-step Running Example

**Input:** `arr = [12, 11, 13, 5, 6]` (n = 5)

### Vòng lặp i = 1: key = 11
```
Trước:  [12, 11, 13, 5, 6]
        [0]  [1]  [2]  [3]  [4]
        
key = 11, nearest = 0
arr[0] = 12 > 11 → shift: arr[1] = arr[0] = 12
nearest = -1 (exit loop)
arr[0] = key = 11

Sau:    [11, 12, 13, 5, 6]
        ✓ Sorted: [11, 12]
```

### Vòng lặp i = 2: key = 13
```
Trước:  [11, 12, 13, 5, 6]
        
key = 13, nearest = 1
arr[1] = 12 < 13 → break (no shift)
arr[2] = key = 13

Sau:    [11, 12, 13, 5, 6]
        ✓ Sorted: [11, 12, 13]
```

### Vòng lặp i = 3: key = 5
```
Trước:  [11, 12, 13, 5, 6]
        
key = 5, nearest = 2
arr[2] = 13 > 5 → shift: arr[3] = 13
nearest = 1
arr[1] = 12 > 5 → shift: arr[2] = 12
nearest = 0
arr[0] = 11 > 5 → shift: arr[1] = 11
nearest = -1 (exit loop)
arr[0] = key = 5

Sau:    [5, 11, 12, 13, 6]
        ✓ Sorted: [5, 11, 12, 13]
```

### Vòng lặp i = 4: key = 6
```
Trước:  [5, 11, 12, 13, 6]
        
key = 6, nearest = 3
arr[3] = 13 > 6 → shift: arr[4] = 13
nearest = 2
arr[2] = 12 > 6 → shift: arr[3] = 12
nearest = 1
arr[1] = 11 > 6 → shift: arr[2] = 11
nearest = 0
arr[0] = 5 < 6 → break
arr[1] = key = 6

Sau:    [5, 6, 11, 12, 13]
        ✓ Sorted: [5, 6, 11, 12, 13]
```

**Kết quả cuối:** `[5, 6, 11, 12, 13]`

---

## Đánh giá thuật toán

### 1. Phân tích độ phức tạp thời gian

| Trường hợp | Time Complexity | So sánh | Dịch chuyển (shifts) | Điều kiện |
|------------|-----------------|---------|---------------------|-----------|
| **Best Case** | **O(n)** | n-1 | 0 | Mảng đã sort tăng dần |
| **Average Case** | O(n²) | ~n²/4 | ~n²/4 | Dữ liệu ngẫu nhiên |
| **Worst Case** | O(n²) | n(n-1)/2 | n(n-1)/2 | Mảng giảm dần |

**Chi tiết:**
- **Best Case O(n):** Mảng đã sort → vòng lặp trong break ngay lập tức, chỉ 1 so sánh mỗi i
- **Worst Case O(n²):** Mảng giảm dần → mỗi key phải dịch chuyển toàn bộ phần tử trước đó
- **Adaptive:** Tự động chạy nhanh hơn khi dữ liệu gần-sorted

### 2. Phân tích không gian bộ nhớ

| Metric | Value | Giải thích |
|--------|-------|------------|
| **Space Complexity** | **O(1)** | In-place sorting |
| **Auxiliary Space** | O(1) | Chỉ dùng `key`, `nearest`, `i` |
| **Recursive Version** | O(n) | Call stack depth = n |
| **Stable** | **Có** | Không đổi thứ tự phần tử bằng nhau (chỉ shift khi `>` không phải `>=`) |
| **Online** | **Có** | Có thể sort khi dữ liệu đến dần (streaming) |

### 3. Ưu điểm

| Ưu điểm | Mô tả |
|---------|-------|
| **Adaptive** | O(n) khi đã sort, O(nk) khi mỗi phần tử cách vị trí đúng ≤ k |
| **Stable** | Giữ thứ tự phần tử bằng nhau - quan trọng cho multi-key sort |
| **Online** | Xử lý luồng dữ liệu, không cần biết n trước |
| **In-place** | O(1) extra memory |
| **Cache-friendly** | Truy cập tuần tự, locality tốt |
| **Low overhead** | Nhanh nhất cho n ≤ 50-100 |
| **Đơn giản** | Dễ implement, ít bug |

### 4. Nhược điểm

| Nhược điểm | Mô tả |
|------------|-------|
| **O(n²) worst-case** | Chậm với n lớn, dữ liệu ngẫu nhiên |
| **Nhiều shifts** | O(n²) gán giá trị (gấp Selection Sort) |
| **Không song song hóa** | Phụ thuộc dữ liệu tuần tự |
| **Recursive version** | O(n) stack space, risk stack overflow |

### 5. Kích thước bài toán phù hợp (Problem Size)

| Kích thước n | Khuyến nghị | Lý do |
|--------------|-------------|-------|
| **n ≤ 10** | ✅ **Tối ưu** | Nhanh hơn mọi thuật toán O(n log n) do overhead thấp |
| **10 < n ≤ 50** | ✅ **Rất tốt** | Thường dùng làm base case cho Quick/Merge Sort |
| **50 < n ≤ 200** | ⚠️ **Chấp nhận** | Vẫn OK nếu dữ liệu gần-sorted |
| **n > 200** | ❌ **Tránh** | Dùng Quick/Merge/Tim Sort |

**Quy tắc thực tế:** 
- n ≤ 50 → Insertion Sort (hoặc Hybrid)
- Dữ liệu gần-sorted (k-small disorder) → Insertion Sort O(nk)
- Online/streaming data → Insertion Sort

### 6. So sánh với các thuật toán O(n²) khác

| Thuật toán | Time (Avg) | Best | Stable | Adaptive | Online | Swaps/Shifts |
|------------|------------|------|--------|----------|--------|--------------|
| **Insertion Sort** | O(n²) | **O(n)** | ✅ | ✅ | ✅ | O(n²) shifts |
| **Selection Sort** | O(n²) | O(n²) | ❌ | ❌ | ❌ | **n swaps** (min) |
| **Bubble Sort** | O(n²) | O(n) | ✅ | ✅ (flag) | ❌ | O(n²) swaps |

### 7. So sánh với thuật toán O(n log n)

| Thuật toán | Time | Space | Stable | Adaptive | Khi nào dùng |
|------------|------|-------|--------|----------|--------------|
| **Insertion Sort** | O(n²) | O(1) | ✅ | ✅ | n ≤ 50, gần-sorted, online |
| **Merge Sort** | O(n log n) | O(n) | ✅ | ❌ | Cần stable, linked list |
| **Quick Sort** | O(n log n)* | O(log n) | ❌ | ❌ | General purpose |
| **Heap Sort** | O(n log n) | O(1) | ❌ | ❌ | Worst-case guarantee |
| **Tim Sort** | O(n log n) | O(n) | ✅ | ✅ | **Production (Python, Java, C++)** |

*Tim Sort = Merge Sort + Insertion Sort (chạy Insertion Sort trên runs nhỏ)*

### 8. Các biến thể cải tiến

**Binary Insertion Sort:**
- Dùng Binary Search tìm vị trí chèn → giảm so sánh từ O(n) → O(log n)
- Vẫn O(n²) shifts → không cải thiện asymptotic
- Hữu ích khi so sánh đắt (string, object phức tạp)

**Binary Insertion Sort - Sample Code:**
```cpp
int binarySearchInsertPos(int arr[], int key, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= key) left = mid + 1;
        else right = mid - 1;
    }
    return left;  // Vị trí chèn (first > key)
}

void BinaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = binarySearchInsertPos(arr, key, 0, i - 1);
        
        // Shift elements to make room
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}
```

**Binary Insertion Sort Recursive:**
```cpp
int binarySearchRec(int arr[], int key, int left, int right) {
    if (left > right) return left;
    int mid = left + (right - left) / 2;
    if (arr[mid] <= key) return binarySearchRec(arr, key, mid + 1, right);
    return binarySearchRec(arr, key, left, mid - 1);
}

void BinaryInsertionSortRecursive(int arr[], int n) {
    if (n <= 1) return;
    BinaryInsertionSortRecursive(arr, n - 1);
    
    int key = arr[n - 1];
    int pos = binarySearchRec(arr, key, 0, n - 2);
    
    for (int j = n - 1; j > pos; j--) {
        arr[j] = arr[j - 1];
    }
    arr[pos] = key;
}
```

**Complexity Analysis:**
| Metric | Standard Insertion Sort | Binary Insertion Sort |
|--------|------------------------|----------------------|
| **Comparisons** | O(n²) worst, O(n) best | **O(n log n)** worst, O(n log n) best |
| **Shifts/Swaps** | O(n²) | O(n²) (unchanged) |
| **Time (Overall)** | O(n²) | O(n²) - same asymptotic |
| **Space** | O(1) | O(1) iterative, O(log n) recursive |

**Khi nào dùng Binary Insertion Sort:**
- So sánh đắt (string so sánh phức tạp, object custom comparator)
- Cần giảm số phép so sánh nhưng chấp nhận shifts
- Không cải thiện được shifts - nếu shifts là bottleneck thì dùng cấu trúc dữ liệu khác (linked list, tree)

**Shell Sort:**
- Generalization của Insertion Sort với gap sequence
- Time: O(n log² n) đến O(n^1.5) tùy gap
- Không stable

**Tim Sort (Production Standard):**
- Chia mảng thành "runs" (đoạn đã sort)
- Sort mỗi run bằng Insertion Sort
- Merge các run bằng Merge Sort
- O(n) best case, O(n log n) worst case, stable, adaptive

### 9. Ứng dụng thực tế

| Lĩnh vực | Ứng dụng |
|----------|----------|
| **STL/Standard Library** | `std::sort` chuyển sang Insertion Sort khi n ≤ 16-32 (introsort) |
| **Tim Sort** | Python `list.sort()`, Java `Arrays.sort()`, Android, GNU Octave |
| **Nearly-sorted data** | Log files, time-series data, incremental updates |
| **Online systems** | Real-time data arrival, streaming |
| **Small arrays** | Base case cho Quick Sort, Merge Sort |
| **External sorting** | Sort runs trước khi merge |

### 10. Tóm tắt

| Đặc điểm | Giá trị |
|----------|---------|
| **Paradigm** | Decrease and Conquer / Incremental |
| **Time (Best)** | **O(n)** |
| **Time (Avg/Worst)** | O(n²) |
| **Space** | O(1) (iterative), O(n) (recursive) |
| **Stable** | **Yes** |
| **Adaptive** | **Yes** |
| **Online** | **Yes** |
| **Swaps/Shifts** | O(n²) worst, 0 best |
| **Comparisons** | n-1 best, n(n-1)/2 worst |
| **Best for** | n ≤ 50, nearly-sorted, online, stable required |

**Kết luận:** Insertion Sort là **"vua của mảng nhỏ"** và **"chuyên gia dữ liệu gần-sorted"**. Nó là building block của Tim Sort - thuật toán sort tiêu chuẩn trong production hiện nay. Luôn ưu tiên Insertion Sort khi n ≤ 50 hoặc dữ liệu có độ disorder thấp (k << n).