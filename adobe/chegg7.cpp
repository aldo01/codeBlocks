#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bubbleSort(vector<int> &a);
int printVector(vector<int> a);
int linear_search(vector<int> a, int);
int main()
{
  int input,n,num;
  vector<int> a;
  cout<<"Enter the number of inputs: ";
  cin>>n;
  cout << "Enter your numbers to be evaluated: " << endl;
  for(int i=0;i<n;i++){
  cin >> input;
  a.push_back(input);
  }
     cout<<"Before sorting: \n ";
     printVector(a);
    bubbleSort(a);
     cout<<"After sorting: \n ";
    printVector(a);
    cout<<"\nEnter the value to be searched:\n ";
     cin>>num;
     linear_search(a,num);

  return 0;
}

int bubbleSort(vector<int>& a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}

int printVector(vector<int> a){
    for (size_t i=0;  i <a.size();  i++) {
        cout<<a[i]<<" ";

    }
  cout<<endl;
}
int linear_search(vector<int> v, int a){
   for (int i = 0; i < v.size(); i++){
      if (v[i] == a)
         cout<<a<<" found at position "<<i;
         return i;
   }
   cout<<"\nValue not found..!!\n";
   return -1;
}
