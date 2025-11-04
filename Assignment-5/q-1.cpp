#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int n) {
        data = n;
        next = NULL;
    }
};

class linkedlist {
private:
    node* head;

public:
    linkedlist() {
        head = NULL;
    }

    int sizeoflist() {
        int size = 0;
        node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    void insertbegin(int n) {
        node* newnode = new node(n);
        newnode->next = head;
        head = newnode;
    }

    void insertend(int n) {
        node* newnode = new node(n);
        if (head == NULL) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void insertafter(int n, int after) {
        node* temp = head;
        while (temp != NULL && temp->data != after) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Node with value " << after << " not found.\n";
            return;
        }
        node* newnode = new node(n);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deletebegin() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteend() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void deletenode(int val) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val) {
            node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Node with value " << val << " not found.\n";
            return;
        }
        node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void searchnode(int val) {
        node* temp = head;
        int pos = 0;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Node with value " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found.\n";
    }

    void display() {
        node* temp = head;
        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }
       
        while (temp != NULL) {
            cout << temp->data << "\n";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    linkedlist list;
    list.insertend(1);
    list.insertend(2);
    list.insertend(3);
    list.display();

    list.insertbegin(0);
    list.display();

    list.insertafter(5, 2);
    list.display();

    list.deletebegin();
    list.display();

    list.deleteend();
    list.display();

    list.deletenode(5);
    list.display();

    list.searchnode(2);
    list.searchnode(10);

    cout << "Size of list: " << list.sizeoflist() << endl;

    return 0;
}

