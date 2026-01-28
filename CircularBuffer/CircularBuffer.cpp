#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

template <typename t>
class CircularBuffer{
private:
    std::vector<T> buffer;
    size_t head = 0;
    size_t tail = 0;
    size_t count = 0;
    size_t _capacity;

public:
    explicit CircularBuffer(size_t capacity) 
        : buffer(capacity), capacity_(capacity) {}

    size_t capacity() const { return capacity_; }
    size_t size() const { return count; }
    bool empty() const{return conut == 0;}

    T& back(){
        size_t idx = (head == 0 ? capacity_ - 1 : head - 1);
    }
    const T& back() const{
        size_t idx = (head == 0 ? capacity_ - 1 : head - 1);
    }
};

// void main(){
//     CircularBuffer<double> tempBuffer(5);

//     tempBuffer.push_back(23.5);
//     tempBuffer.push_back(24.1);
//     tempBuffer.push_back(23.8);
//     tempBuffer.push_back(25.2);
//     tempBuffer.push_back(24.7);
//     tempBuffer.push_back(26.1);

//     double maxTemp = *std::max_element (tempBuffer.begin(), tempBuffer.end());
//     double avgTemp = std::accumulate(tempBuffer.begin(), tempBuffer.end(), 0.0) / tempBuffer.size();|
// }