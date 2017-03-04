#include <stdio.h>

int main()
{
    int n, i;
    float num[100], xsum = 0.0, average;

    printf("Enter the numbers of elements: ");
    scanf("%d", &n);

    while  (n <= 0)
    {
        printf("Enter the number again: ");
        scanf("%d", &n);
    }

    for(i = 0; i < n; ++i)
    {
        printf("%d. Enter number: ", i+1);
        scanf("%f", &num[i]);
        xsum += num[i];
    }

    average = xsum / n;
    printf("Standard deviation = %.2f", average);

    return 0;
}
