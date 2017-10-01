#include <iostream>
#include<stdio.h>


using namespace std;

int bubbleSort(int [], int);
int linearSearch(int [], int, int);
int main() {
 int num;
 int * Array;
    cout<<"Enter array size : ";
    int Size =0;
    cin >> Size;

    Array = new int[Size]; //allocate memory for our array
    cout<<"Enter the array elements: ";

    for(int i=0;i<Size;++i)
        cin>>Array[i];
         cout<<"\nArray before sorting:\n ";
    for(int i = 0; i < Size; i++){
      cout<<" "<<Array[i];
    }
     bubbleSort(Array, Size); //bubbleSort it
     cout<<"\nEnter the value to be searched:\n ";
     cin>>num;
     int res= linearSearch(Array,num,Size);


   return 0;
}

 int bubbleSort(int Array[], int arraySize){
 int temp;
    for(int i=1;i<arraySize;++i)
    {
        for(int j=0;j<(arraySize-i);++j)
            if(Array[j]>Array[j+1])
            {
                temp=Array[j];
                Array[j]=Array[j+1];
                Array[j+1]=temp;
            }
    }

    cout<<"\nArray after sort:\n";
    for(int i=0;i<arraySize;++i)
        cout<<" "<<Array[i];

    return 0;

 }

 int linearSearch(int arr[], int num, int n){
 int  c=0, pos;
  for(int i=0; i<n; i++)
	{
		if(arr[i]==num)
		{
			c=1;
			pos=i+1;
			break;
		}
	}
	if(c==0)
	{
		cout<<"\nValue not found..!!\n";
	}
	else
	{
		cout<<num<<" found at position "<<pos;
	}
 }

