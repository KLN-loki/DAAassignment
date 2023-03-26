// 2. Sort the strings ("Srinivas", "Lakshmi",  "Gopi", "Krishna", "Rama", "Partha")  in dictionary order using Selection Sort, Insertion Sort, Merge Sort and Quick Sort.

// insertion sort

#include <stdio.h>
#include <string.h>

int main()
{
    char arr[][20] = {"Srinivas", "Lakshmi", "Gopi", "Krishna", "Rama", "Partha"};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);
    int i, j;
    for (i = 1; i < n; i++)
    {
        int j = i;
        char temp[20];
        strcpy(temp, arr[i]);
        while (j > 0 && strcmp(arr[j - 1], temp) > 0)
        {
            strcpy(arr[j], arr[j - 1]);
            j--;
        }
        strcpy(arr[j], temp);
    }
    printf("Sorted array in Dictionary Order:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    return 0;
}

// Output:
// 6
// Sorted array in Dictionary Order:
// Gopi
// Krishna
// Lakshmi
// Partha
// Rama
// Srinivas