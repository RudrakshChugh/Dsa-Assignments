/*
Develop a menu driven program for the following operations of on a Doubly Linked List.
(a) Insertion anywhere in the linked list (As a first node, as a last node, and
after/before a specific node).
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
deleted may appear as a head node, last node or a node in between.
(c) Search for a node.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(){
        data = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    Node(int data, Node* prev, Node* next){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node* insertAtBeginning(Node* head, int data)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node* head,int data)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insertAfterNode(Node* head,int data, int afterData)
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return head;
    }
    Node* temp = head;
    while(temp != NULL && temp->data != afterData)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout << "Node not found" << endl;
        return head;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

Node* insertBeforeNode(Node* head, int data, int beforeData)
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return head;
    }
    if(head->data == beforeData)
    {
        return insertAtBeginning(head, data);
    }
    Node* temp = head;
    while(temp != NULL && temp->data != beforeData)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout << "Node not found" << endl;
        return head;
    }
    Node* newNode = new Node(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    return head;
}

Node* deleteNode(Node* head, int data)
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    
    Node* temp = head;
    while(temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }
    
    if(temp == NULL)
    {
        cout << "Node not found" << endl;
        return head;
    }
    
    if(temp == head)
    {
        head = temp->next;
        if(head != NULL)
            head->prev = NULL;
        delete temp;
        return head;
    }
    
    if(temp->next == NULL)
    {
        temp->prev->next = NULL;
        delete temp;
        return head;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return head;
}

int searchNode(Node* head, int data)
{
    Node* temp = head;
    int cnt = 1;
    while(temp != NULL)
    {
        if(temp->data == data)
            return cnt;
        temp = temp->next;
        cnt++;
    }
    cout << "Node not found" << endl;
    return cnt;
}

void display(Node* head)
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(Node* &head)
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node* head = NULL;
    int choice, data, positionData;
    int found = NULL;  // Moved declaration outside switch
    
    do
    {
        cout << "\n1. Insert at beginning";
        cout << "\n2. Insert at end";
        cout << "\n3. Insert after node";
        cout << "\n4. Insert before node";
        cout << "\n5. Delete node";
        cout << "\n6. Search node";
        cout << "\n7. Display";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                head = insertAtBeginning(head, data);
                break;
                
            case 2:
                cout << "Enter data: ";
                cin >> data;
                head = insertAtEnd(head, data);
                break;
                
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter after which data: ";
                cin >> positionData;
                head = insertAfterNode(head, data, positionData);
                break;
                
            case 4:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter before which data: ";
                cin >> positionData;
                head = insertBeforeNode(head, data, positionData);
                break;
                
            case 5:
                cout << "Enter data to delete: ";
                cin >> data;
                head = deleteNode(head, data);
                break;
                
            case 6:
            {   // Added braces for proper scope
                cout << "Enter data to search: ";
                cin >> data;
                found = searchNode(head, data);
                if(found != NULL)
                    cout << "Node found with data: " << found << endl;
                break;
            }
            
            case 7:
                display(head);
                break;
            
            case 8:
                deleteList(head);
                head = NULL;  // Ensure head is NULL after deletion
                cout << "List deleted successfully\n";
                break;
            
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 8);
    
    if(head != NULL)  // Cleanup if user exits without using option 8
        deleteList(head);
    
    return 0;
}