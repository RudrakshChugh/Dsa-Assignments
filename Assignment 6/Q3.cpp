/*
Write a program to find size of
i. Doubly Linked List.
ii. Circular Linked List.
*/

#include<bits/stdc++.h>
using namespace std;

struct CircularNode{
    int data;
    CircularNode* next;
    CircularNode(){
        data=0;
        next=NULL;
    }
    CircularNode(int x){
        data=x;
        next=NULL;
    }
    CircularNode(int x, CircularNode* next){
        data=x;
        this->next=next;
    }
};

struct DoublyNode{
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(){
        data=0;
        next=NULL;
        prev=NULL;
    }
    DoublyNode(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
    DoublyNode(int x, DoublyNode* next, DoublyNode* prev){
        data=x;
        this->next=next;
        this->prev=prev;
    }
};

int circularListSize(CircularNode* head){
    if(head==NULL){
        return 0;
    }
    CircularNode* temp=head;
    int count=0;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count+1;
}
int doublyListSize(DoublyNode* head){
    if(head==NULL){
        return 0;
    }
    DoublyNode* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

CircularNode* arr2CircularLL(int arr[], int n){
    CircularNode* head=new CircularNode(arr[0]);
    CircularNode* temp=head;
    for(int i=1;i<n;i++){
        temp->next=new CircularNode(arr[i]);
        temp=temp->next;
    }
    temp->next=head;
    return head;
}

DoublyNode* arr2DoublyLL(int arr[], int n){
    DoublyNode* head=new DoublyNode(arr[0]);
    DoublyNode* temp=head;
    for(int i=1;i<n;i++){
        DoublyNode* newNode=new DoublyNode(arr[i]);
        temp->next=newNode;
        newNode->prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    int circularArr[]={10,20,30,40,50};
    int doublyArr[]={5,15,25,35,45,55};
    int n1=sizeof(circularArr)/sizeof(circularArr[0]);
    int n2=sizeof(doublyArr)/sizeof(doublyArr[0]);
    CircularNode* circularHead=arr2CircularLL(circularArr,n1);
    DoublyNode* doublyHead=arr2DoublyLL(doublyArr,n2);
    cout<<"Size of Circular Linked List: "<<circularListSize(circularHead)<<endl;
    cout<<"Size of Doubly Linked List: "<<doublyListSize(doublyHead)<<endl;
    return 0;
}

