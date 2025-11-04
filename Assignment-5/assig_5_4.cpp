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
    
void reverse(){
	node* pre = NULL;
	node* curr = head ;
	node* next = NULL ;
	
	while(curr != NULL){
		next = curr->next ;
		curr->next = pre ;
		pre = curr ;
		curr = next ;	
}
head = pre ;
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
int main(){
	linkedlist list ;
	list.insertend(1);
	list.insertend(2);
	list.insertend(3);
	list.insertend(4);
	list.display();
	list.reverse();
	list.display();
	return 0 ;
	}
