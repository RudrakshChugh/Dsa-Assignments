/*
Display all the node values in a circular linked list, repeating value of head node at the
end too. 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int x){
        data=x;
        next=NULL;
    }
    Node(int x, Node* next){
        data=x;
        this->next=next;
    }
};

void display(Node* head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}

Node* arr2LL(int arr[], int n){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<n;i++){
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    temp->next=head;
    return head;
}

int main(){
    int arr[]={10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* head=arr2LL(arr,n);
    display(head);
    return 0;
}