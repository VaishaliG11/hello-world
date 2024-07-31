#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int sum = 0;
    float average;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the integers: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    average= (float)sum/n;
    printf("The average of the array elements is: %.2f\n", average);


    return 0;
}
