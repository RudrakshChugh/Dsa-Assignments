/*
Write a program to check if a linked list is Circular Linked  or not.
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
    }
    Node(int x, Node* next){
        data = x;
        this->next = next;
    }
};

void detectCircular(Node* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout<<"The linked list is circular"<<endl;
            return;
        }
    }
    cout<<"The linked list is not circular"<<endl;
}

Node* arr2CircularLL(int arr[], int n){
    if(n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < n; i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    temp->next = head; // Making the list circular
    return head;
}

Node* arr2LL(int arr[], int n){
    if(n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < n; i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = arr2CircularLL(arr, n);
    detectCircular(head);

    Node* head2 = arr2LL(arr, n);
    detectCircular(head2);
    return 0;
}