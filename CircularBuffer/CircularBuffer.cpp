#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>
#include <iterator>


template <typename T>
class CircularBuffer{
public:
    explicit CircularBuffer(size_t capacity);
};

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t capacity)
    : buffer_(capacity),
      capacity_(capacity),
      head_(0),
      tail_(0),
      size_(0)
{
    if (capacity == 0)
        throw std::invalid_argument("capacity must be > 0");
}

void begin(){}
void end(){}
void size(){}
void capacity(){}
void empty(){}

void push_back (const T& item){}
void pop_front(){}
void front(){}
void back() {}