/*
Write a program to check if a doubly linked list of characters is palindrome or not.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* prev;
    Node* next;
    Node(){
        data = '\0';
        prev = NULL;
        next = NULL;
    }
    Node(char data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    Node(char data, Node* prev, Node* next){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

bool isPalindrome(Node* head){
    if(head == NULL) return true;    
    Node* left = head;
    Node* right = head;    
    while(right->next != NULL) right = right->next;
    while(left != right && right->next != left){
        if(left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }    
    return true;
}

Node* string2DLL(string str){
    if(str.empty()) return NULL;    
    Node* head = new Node(str[0]);
    Node* temp = head;    
    for(size_t i = 1; i < str.length(); i++){
        Node* newNode = new Node(str[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }    
    return head;
}

int main(){
    string str = "racecare";
    Node* head = string2DLL(str);
    if(isPalindrome(head))
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;
    return 0;
}

