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
    // 생성자
    explicit CircularBuffer(size_t capacity) 
        : buffer(capacity), capacity_(capacity) {}


    void begin()
    void end()
    //용량 반환
    size_t capacity() const { return _capacity; }
    size_t size() const { return count; }
    bool empty() const{return conut == 0;}

    //return lastest data
    T& front() { return buffer[tail]; }
    const T& front() const { return buffer[tail]; }

    //return newest data
    T& back(){
        size_t idx = (head == 0 ? _capacity - 1 : head - 1);
        return buffer[idx];
    }
    const T& back() const{
        size_t idx = (head == 0 ? _capacity - 1 : head - 1);
        return buffer[idx];
    }

    //add new data
    void push_back(const T& item){
        buffer[head] = item;
        head = (head+1) % _capacity;
        if(count < _capacity){
            count++;
        }
        else{
            tail = (tail+1) % _capacity;
        }
    }

    //delete lastest data
    void pop_front(){
        if(count == 0) return;
        tail = (tail + 1) % _capacity;
        count--;
    }

    class iterator{
        iterator(CircularBuffer* c, size_t start, size_t iter = 0)
        : cb(c), idx(start), iterated(iter) {}
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