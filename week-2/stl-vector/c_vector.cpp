#include "c_vector.hpp"
#include <algorithm>

template <typename T>
c_vector<T>::c_vector() : size_(0), capacity_(1), arr(new T[1]) {}

template <typename T>
c_vector<T>::~c_vector() {
    delete[] arr;
}

template <typename T>
c_vector<T>::c_vector(const c_vector& other) : size_(other.size_), capacity_(other.capacity_), arr(new T[other.capacity_]) {
    for (int i = 0; i < size_; ++i) arr[i] = other.arr[i];
}

template <typename T>
c_vector<T>& c_vector<T>::operator=(const c_vector& other) {
    if (this != &other) {
        delete[] arr;
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr = new T[capacity_];
        for (int i = 0; i < size_; ++i) arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
void c_vector<T>::resize() {
    capacity_ *= 2;
    T* new_arr = new T[capacity_];
    for (int i = 0; i < size_; ++i) new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;
}

template <typename T>
T& c_vector<T>::operator[](int index) {
    return arr[index];
}

template <typename T>
const T& c_vector<T>::operator[](int index) const {
    return arr[index];
}

template <typename T>
int c_vector<T>::size() const {
    return size_;
}

template <typename T>
int c_vector<T>::capacity() const {
    return capacity_;
}

template <typename T>
bool c_vector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
void c_vector<T>::clear() {
    size_ = 0;
}

template <typename T>
void c_vector<T>::push_back(const T& value) {
    if (size_ == capacity_) resize();
    arr[size_++] = value;
}

template <typename T>
void c_vector<T>::pop_back() {
    if (size_ == 0) throw std::out_of_range("Vector is empty");
    --size_;
}

template <typename T>
void c_vector<T>::insert(int index, const T& value) {
    if (index < 0 || index > size_) throw std::out_of_range("Index out of range");
    if (size_ == capacity_) resize();
    for (int i = size_; i > index; --i) arr[i] = arr[i-1];
    arr[index] = value;
    ++size_;
}

template <typename T>
void c_vector<T>::erase(int index) {
    if (index < 0 || index >= size_) throw std::out_of_range("Index out of range");
    for (int i = index; i < size_ - 1; ++i) arr[i] = arr[i + 1];
    --size_;
}

template <typename T>
void c_vector<T>::swap(c_vector& other) {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(arr, other.arr);
}

template <typename T>
T* c_vector<T>::begin() {
    return arr;
}

template <typename T>
const T* c_vector<T>::begin() const {
    return arr;
}

template <typename T>
T* c_vector<T>::end() {
    return arr + size_;
}

template <typename T>
const T* c_vector<T>::end() const {
    return arr + size_;
}

template class c_vector<int>;
template class c_vector<double>;
template class c_vector<char>;
template class c_vector<std::string>;