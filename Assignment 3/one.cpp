#include<iostream>
using namespace std;

class stack{
    //properties
    public:
        int *arr;
        int top;
        int size;

    //behaviour
    stack(int size){    // constructor that creates stack
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        // check if the array is empty or not 
        if(size - top > 1){     // if true it has atleast one empty space
            top++;
            arr[top] = element;
        }else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        // atleast one element must br present to pop element
        if(top >= 0){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        // top must be in valid range
        if(top>=0){
            return arr[top];
        }else{
            cout<<"stack is Empty"<<endl;
            return -1;
        }
    }

    bool empty(){
        // if top same then empty
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

};

int main(){

    stack st(5);
    st.push(22);
    st.push(43); // if we add more element than size the it gives stack overflow

    cout<<st.peek()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}