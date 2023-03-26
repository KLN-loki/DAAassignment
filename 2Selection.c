// 2. Sort the strings ("Srinivas", "Lakshmi",  "Gopi", "Krishna", "Rama", "Partha")  in dictionary order using Selection Sort, Insertion Sort, Merge Sort and Quick Sort.

// selection sort
#include <stdio.h>
#include <string.h>

int main()
{
    char arr[][20] = {"Srinivas", "Lakshmi", "Gopi", "Krishna", "Rama", "Partha"};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        char temp[20];
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
    }
    printf("Sorted array in Dictionary Order:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    return 0;
}

// Output:
// Sorted array in Dictionary Order:
// Gopi
// Krishna
// Lakshmi
// Partha
// Rama
// Srinivas