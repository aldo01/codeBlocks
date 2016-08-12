#include <stdio.h>

int getOddOccurrence(int ar[], int ar_size)
{
     int i;
     int res = 0;
     for (i=0; i < ar_size; i++)
        res = res ^ ar[i];
       // printf(" %d ",3^0);
       return res;
}

/* Diver function to test above function */
int main()
{
     int ar[] = {2, 2,3,3,3};
     int n = sizeof(ar)/sizeof(ar[0]);
     printf("%d", getOddOccurrence(ar, n));
     return 0;
}
