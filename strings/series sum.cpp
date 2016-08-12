// A simple C++ program to compute sum of series 1/1! + 1/2! + .. + 1/n!
#include <iostream>
using namespace std;

// An Efficient Function to return value of 1/1! + 1/2! + .. + 1/n!
double sum(long long int n)
{
    long  double sum = 0;
   long int fact = 1;
    for (int i = 1; i <= n; i++)
    {
       fact *= i;         // Update factorial
       sum += 1.0/fact;   // Update series sum
    }
    return sum;
}

// Driver program to test above functions
int main()
{
   long long int n = 10;
    cout << sum(n);
    return 0;
}
