#include <iostream>
using namespace std;

template <typename T>
class Queue 
{
private:
    T* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue() {
        capacity = 10; // Initial capacity (you can change this as per your requirement)
        arr = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(const T& item) {
        if (count == capacity) {
            // Queue is full, need to resize the array
            int newCapacity = capacity * 2;
            T* newArr = new T[newCapacity];

            for (int i = 0; i < capacity; ++i) {
                newArr[i] = arr[(front + i) % capacity];
            }

            delete[] arr;
            arr = newArr;
            front = 0;
            rear = count - 1;
            capacity = newCapacity;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            // Queue is empty
            throw std::underflow_error("Queue is empty");
        }

        front = (front + 1) % capacity;
        count--;
    }

    T& peek() {
        if (count == 0) {
            // Queue is empty
            throw std::underflow_error("Queue is empty");
        }

        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }
    void display() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        int current = front;
        for (int i = 0; i < count; i++) {
            cout << arr[current] << " ";
            current = (current + 1) % capacity;
        }
        cout << endl;
    }
};