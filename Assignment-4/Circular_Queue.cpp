/*
it a normal queue just difference is 
 When rear reaches the end of the array, it wraps around to the front if there is empty space.
*/

#include <iostream>                  
using namespace std;

class CircularQueue {
    int* arr;                         
    int front;                         
    int rear;                         
    int size;                         

public:
    
    CircularQueue(int n) {
        size = n;                     
        arr = new int[size];         
        front = rear = -1;           
    }

    
    bool enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)) {
            return false;            
        }
        else if (front == -1) {      
            front = rear = 0;        
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;                
        }
        else {
            rear++;                 
        }

        arr[rear] = value;           
        return true;                 
    }

    int dequeue() {
        if (front == -1) {          
            return -1;               
        }

        int ans = arr[front];        
        arr[front] = -1;           

        if (front == rear) {
            front = rear = -1;       
        }
        else if (front == size - 1) {
            front = 0;              
        }
        else {
            front++;                
        }

        return ans;                 
    }
};



int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); 

    cout << q.dequeue() << endl; 
    q.enqueue(60);               

    cout << q.dequeue() << endl; 
}

