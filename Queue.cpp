#include <iostream>
using namespace std;

class MyCircularQueue {
private:
    int* queue;
    int head;
    int tail;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        queue = new int[k];
        head = -1;
        tail = -1;
        size = 0;
        capacity = k;
    }

    ~MyCircularQueue() {
        delete[] queue;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % capacity;
        queue[tail] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {  
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % capacity;
        }
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[tail];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    int queueSize;
    cout << "Enter the size of the circular queue: ";
    cin >> queueSize;

    MyCircularQueue circularQueue(queueSize);

    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Rear\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                if (circularQueue.enQueue(value)) {
                    cout << "Enqueued " << value << " successfully.";
                } else {
                    cout << "Queue is full. Cannot enqueue.";
                }
                break;
            case 2:
                if (circularQueue.deQueue()) {
                    cout << "Dequeued successfully.";
                } else {
                    cout << "Queue is empty. Cannot dequeue.";
                }
                break;
            case 3:
                value = circularQueue.Front();
                if (value != -1) {
                    cout << "Front element is: " << value;
                } else {
                    cout << "Queue is empty.";
                }
                break;
            case 4:
                value = circularQueue.Rear();
                if (value != -1) {
                    cout << "Rear element is: " << value;
                } else {
                    cout << "Queue is empty.";
                }
                break;
            case 5:
                cout << (circularQueue.isEmpty() ? "Queue is empty." : "Queue is not empty.");
                break;
            case 6:
                cout << (circularQueue.isFull() ? "Queue is full." : "Queue is not full.");
                break;
            case 7:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Try again.";
        }
    } while (choice != 7);

    return 0;
}
