#ifndef C_VECTOR_HPP
#define C_VECTOR_HPP

#include <iostream>
#include <utility>
#include <stdexcept>

template <typename T>
class c_vector {
private:
    int size_;
    int capacity_;
    T* arr;

    void resize();

public:
    c_vector();
    ~c_vector();

    c_vector(const c_vector& other);
    c_vector& operator=(const c_vector& other);

    T& operator[](int index);
    const T& operator[](int index) const;

    int size() const;
    int capacity() const;
    bool empty() const;

    void clear();
    void push_back(const T& value);
    void pop_back();
    void insert(int index, const T& value);
    void erase(int index);
    void swap(c_vector& other);

    T* begin();
    const T* begin() const;
    T* end();
    const T* end() const;
};

#endif