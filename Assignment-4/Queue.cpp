/*
Enqueue (Insert) → Add element at the rear.

Dequeue (Remove) → Remove element from the front.

Peek/Front → Show the element at the front (without removing).

isEmpty → Check if the queue is empty.

isFull → Check if the queue is full (array implementation).
*/

#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return qfront == rear;
    }

    bool isFull() {
        return (rear == size);
    }

    void push(int data) {   // enqueue
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int pop() { // dequeue
        if (qfront == rear) {
            cout << "Queue Underflow"<<endl;
            return -1;
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1; 
            qfront++;
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (qfront == rear) {
            return -1; 
        } else {
            return arr[qfront];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = qfront; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
int choice, value;
    Queue q;   // ✅ uses fixed size = 100001

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front)\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.push(value);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            value = q.front();
            if (value == -1)
                cout << "Queue is empty" << endl;
            else
                cout << "Front element: " << value << endl;
            break;
        case 4:
            cout << (q.isEmpty() ? "Queue is Empty" : "Queue is Not Empty") << endl;
            break;
        case 5:
            cout << (q.isFull() ? "Queue is Full" : "Queue is Not Full") << endl;
            break;
        case 6:
            q.display();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
