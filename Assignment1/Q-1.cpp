#include<iostream>
using namespace std;
int size = 0;
int arr[100];
void create(){
	cout<<"enter number of Elements"<<endl;
	cin>>size;
	
	cout<<"Enter the Elements"<<endl;
	for(int i = 0 ; i < size;++i){
		cin>>arr[i];
	}
	cout<<"Array Created Successfully"<<endl;
}

void display(){
	if(size==0){
		cout<<"Empty Array"<<endl;
		return;
	}
	cout<<"Array Elements"<<endl;
	for(int i = 0 ; i < size;i++){
		cout<<arr[i]<<" ";
	}
	cout << endl; 
}
void insert(){
	int element , position;
	cout<<"Enter the Element you want to insert"<<endl;
	cin>>element;
	cout<<"Enter the position you want to insert"<<endl;
	cin>>position;
	
	if(position <0 || position > size){
		cout<<"Invalid Position"<<endl;
		return;
	}
	
	for(int i =size ; i > position ; i--){
		arr[i] = arr[i-1];
	}
	arr[position] = element;
	size++;
	
	cout<<"Elements Inserted Successfully"<<endl;
}

void deletion(){
	int position;
	
	if(size == 0){                   
        cout << "Empty Array" << endl;
        return;
    }
	
	cout<<"Enter the position you want to delete"<<endl;
	cin >> position;
	
	if(position <0 || position >= size){  
		cout<<"Invalid Position"<<endl;
		return;
	}
	
	for(int i = position ; i < size-1; ++i){
		arr[i] = arr[i+1];
	}
	size--; 
	
	cout<<"Element deleted Successfully"<<endl; 
}

int linearSearch(){
	int element,i;
	
	if(size == 0){
		cout<<"Empty Array"<<endl;
		return -1;
	}
	
	cout<<"Enter element to Search"<<endl;
	cin>>element;
	for(int i = 0 ; i < size ; i++){
		if(arr[i]==element){
			return i;
		}
	}
	return -1;
}
int main(){
	while(true){
		cout<<"Press 1 to Create an Array"<<endl;      
		cout<<"Press 2 to Display an Array"<<endl;    
		cout<<"Press 3 to Insert in an Array"<<endl;   
		cout<<"Press 4 for Linear Search"<<endl;
		cout<<"Press 5 to Delete an Element"<<endl;
		cout<<"Press 0 to Exit"<<endl;                   
	
		int a;
		cout<<"Enter Your Choice:"<<endl;
		cin>>a;
	
	
		switch(a){
			case(1): create(); break;
			
			case(2):display(); break;
		
			case(3):insert(); break;
				
			case(4):{
				int idx = linearSearch();
				if(idx == -1)
					cout<<"Element not found"<<endl;
				else
					cout<<"Element found at position: "<< idx << endl;
				break;
			}
				
			case(5):deletion(); break;

			case(0): return 0;  

			default: cout<<"Invalid Input"<<endl;
		}
	}
	return 0;
}
