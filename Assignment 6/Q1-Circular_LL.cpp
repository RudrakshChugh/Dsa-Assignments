/*
Develop a menu driven program for the following operations of on a Circular Linked List.
(a) Insertion anywhere in the linked list (As a first node, as a last node, and
after/before a specific node).
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
deleted may appear as a head node, last node or a node in between.
(c) Search for a node.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};


Node *insertAtBeginning(Node* head, int data)
{
    Node *newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;  // Make it circular
        return head;
    }
    Node *temp = head;
    while(temp->next != head)  // Find last node
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;  // Update last node
    head = newNode;
    return head;
}

Node* insertAtEnd(Node* head,int data)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return head;
    }
    Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* insertAfterNode(Node* head,int data,int afterData)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return head;
    }
    Node* temp = head;
    while(temp->data != afterData)
    {
        temp = temp->next;
        if(temp == head)
        {
            cout << "Node not found" << endl;
            return head;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertBeforeNode(Node* head,int data,int beforeData)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        newNode->next = head;
        return head;
    }
    
    // If inserting before head
    if(head->data == beforeData)
    {
        return insertAtBeginning(head, data);
    }
    
    Node* temp = head;
    Node* prev = NULL;
    do
    {
        if(temp->next->data == beforeData)
        {
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    } while(temp != head);
    
    cout << "Node not found" << endl;
    return head;
}

Node* deleteNode(Node* head, int data)
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    
    // If only one node exists
    if(head->next == head && head->data == data)
    {
        delete head;
        return NULL;
    }
    
    // If head node is to be deleted
    if(head->data == data)
    {
        Node* temp = head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        return head;
    }
    
    // For other nodes
    Node* temp = head;
    while(temp->next != head && temp->next->data != data)
    {
        temp = temp->next;
    }
    
    if(temp->next == head)
    {
        cout << "Node not found" << endl;
        return head;
    }
    
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    return head;
}

Node* searchNode(Node* head,int data)
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    Node* temp = head;
    do
    {
        if(temp->data == data)
            return temp;
        temp = temp->next;
    } while(temp != head);
    
    cout << "Node not found" << endl;
    return NULL;
}

void display(Node* head)
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteList(Node* &head)  // Changed to reference parameter
{
    if (head == NULL) return;
    
    Node* current = head->next;
    Node* next;
    
    while (current != head)
    {
        next = current->next;
        delete current;
        current = next;
    }
    delete head;
    head = NULL;  // Set head to NULL after deletion
}

int main(){
    Node* head = NULL;
    int choice;
    int data;
    int afterData;
    int beforeData;
    Node* foundNode;  // Moved declaration here to fix scope issue
    
    do
    {
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert after node" << endl;
        cout << "4. Insert before node" << endl;
        cout << "5. Delete node" << endl;
        cout << "6. Search node" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
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
            cout << "Enter after node data: ";
            cin >> afterData;
            head = insertAfterNode(head, data, afterData);
            break;
        case 4:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter before node data: ";
            cin >> beforeData;
            head = insertBeforeNode(head, data, beforeData);
            break;
        case 5:
            cout << "Enter data: ";
            cin >> data;
            head = deleteNode(head, data);
            break;
        case 6:
            cout << "Enter data: ";
            cin >> data;
            foundNode = searchNode(head, data);
            if (foundNode != NULL)
            {
                cout << "Node found with data: " << foundNode->data << endl;
            }
            break;
        case 7:
            display(head);
            break;
        case 8:
            deleteList(head);  // Now properly sets head to NULL
            cout << "List deleted successfully" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 8);
    return 0;
}