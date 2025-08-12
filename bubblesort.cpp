#include <iostream>
using namespace std;
int main()
{
	int arr1[]={64,34,25,12,22,11,90};
	int i,j,num1;
	int len=sizeof(arr1)/sizeof(arr1[0]);
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if (arr1[j]>arr1[j+1])
			{
				num1=arr1[j];
				arr1[j]=arr1[j+1];
				arr1[j+1]=num1;
			}
		}
	}
	for (i=0;i<len;i++)
	{
		cout<<arr1[i]<<"\t";
	}
}
