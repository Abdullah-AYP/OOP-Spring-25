#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T, int CAPACITY = 5>
class Queue {
    T data[CAPACITY];
    int front,rear,count;
public:
    Queue() : front(0),rear(0),count(0){}

    void enqueue(T value) {
        if(count == CAPACITY)
            throw QueueOverflowException();
        data[rear] = value;
        rear = (rear + 1) % CAPACITY;
        count++;
    }
    T dequeue() {
        if(count == 0)
            throw QueueUnderflowException();
        T val = data[front];
        front = (front + 1) % CAPACITY;
        count--;
        return val;
    }
    void display() const {
        cout << "Queue: ";
        for (int i = 0, idx = front; i < count; ++i, idx = (idx + 1) % CAPACITY)
            cout << data[idx] << " ";
        cout << endl;
    }
};
int main() {
    Queue<int> q;

    try {
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        q.enqueue(6);  
    }
    catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException\n";
        cout << "Default message: " << e.what() << endl;
    }
    try {
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();  
    }
    catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException\n";
        cout << "Default message: " << e.what() << endl;
    }

    return 0;
}


