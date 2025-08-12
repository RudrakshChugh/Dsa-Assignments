#include<iostream>
using namespace std;
int main(){
	int count = 0;
	int arr[] = {1,3,2,5,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0 ; i < size; i++){
		for(int j = i + 1; j < size ; j++){
			if(arr[i]>arr[j]){
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}
