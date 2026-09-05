# Sorting Algorithm - Giải thuật Sắp xếp

## Bài toán

Cho danh sách `A` gồm `N` phần tử `A[0], A[1], ..., A[N - 1]`. Thực hiện hoán đổi các phần tử `A[i]` và `A[j]` bất kì sao cho `A[i] < A[j]`. Tức với mọi `i, j` bất kì trong khoảng `[0..N-1]`, `A[i] < A[j]`

## Phân loại Giải thuật Sắp xếp

### Theo tính chất của dãy ban đầu

#### Offline Sorting

**Điều kiện**: Toàn bộ các phần tử thuộc danh sách `A` được xử lý đồng thời trong quá trình sắp xếp (Tức đã biết đầy đủ `N` phần tử thuộc `A`)

**Ví dụ**:
- [Selection Sort]()
- [Bubble Sort]()
- [Quick Sort]()

#### Online Sorting

**Điều kiện**: Từng phần tử của `A` được đưa vào thực hiện so sánh và sắp xếp tuần tự mà không cần biết trước toàn bộ danh sách

**Ví dụ**:
- [Insertion Sort]()
- [Tree Sort - BST (Binary Search Tree)]()

### Theo trật tự của kết quả

#### Stable Sorting

**Điều kiện**: Trật tự trước-sau của các phần tử có cùng giá trị trong dãy gốc KHÔNG THAY ĐỔI so với ban đầu

#### Unstable Sorting

**Điều kiện**: Trật tự trước-sau của các phần tử có cùng giá trị trong dãy gốc THAY ĐỔI so với ban đầu

### Theo nơi lưu trữ của danh sách

#### Internal Sorting

**Điều kiện**: Toàn bộ danh sách `A` được lưu trên **RAM** trong quá trình sắp xếp

**Ví dụ**: Interchange Sort, Insertion Sort, Quick Sort

#### External Sorting

**Điều kiện**: Kích thước lớn, toàn bộ danh sách được lưu trên bộ nhớ ngoài **HDD**
**Ví dụ**: Merge Sort