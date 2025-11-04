/*
it a normal queue just difference is 
 When rear reaches the end of the array, it wraps around to the front if there is empty space.
*/

#include <iostream>                   // For input/output operations
using namespace std;

class CircularQueue {
    int* arr;                         // Dynamically allocated array to hold queue elements
    int front;                        // Points to the front element of the queue
    int rear;                         // Points to the last element inserted
    int size;                         // Maximum size of the queue

public:
    
    CircularQueue(int n) {
        size = n;                     // Set the size of the queue
        arr = new int[size];         // Allocate memory for the queue
        front = rear = -1;           // Initialize front and rear as -1 (queue is empty)
    }

    // Enqueue: insert an element into the circular queue
    bool enqueue(int value) {
        // Condition to check if queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)) {
            return false;            // Return false if insertion not possible
        }
        else if (front == -1) {      // First element to be inserted
            front = rear = 0;        // Set front and rear to 0
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;                // Wrap around rear to 0 (circular)
        }
        else {
            rear++;                  // Move rear to next index normally
        }

        arr[rear] = value;           // Insert the value at rear index
        return true;                 // Return true indicating successful insertion
    }

    // Dequeue: remove an element from the front of the circular queue
    int dequeue() {
        if (front == -1) {           // Check if queue is empty
            return -1;               // Return -1 if no elements to remove
        }

        int ans = arr[front];        // Store the value to be removed
        arr[front] = -1;             // Optional: mark the slot as empty

        if (front == rear) {         // Queue has only one element
            front = rear = -1;       // Reset to empty state
        }
        else if (front == size - 1) {
            front = 0;               // Wrap around front to 0 (circular)
        }
        else {
            front++;                 // Move front to next index normally
        }

        return ans;                  // Return the dequeued element
    }
};



int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // Should fail if queue is full

    cout << q.dequeue() << endl; // 10
    q.enqueue(60);               // Wraps around

    cout << q.dequeue() << endl; // 20
}
