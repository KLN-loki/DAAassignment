// 2. Sort the strings ("Srinivas", "Lakshmi",  "Gopi", "Krishna", "Rama", "Partha")  in dictionary order using Selection Sort, Insertion Sort, Merge Sort and Quick Sort.

// Merge sort
#include <stdio.h>
#include <string.h>

void merge(char arr[][20], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    char L[n1][20], R[n2][20];
    for (i = 0; i < n1; i++)
        strcpy(L[i], arr[l + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], arr[m + 1 + j]);
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i], R[j]) <= 0)
        {
            strcpy(arr[k], L[i]);
            i++;
        }
        else
        {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }
    while (j < n2)
    {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][20], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    char arr[][20] = {"Srinivas", "Lakshmi", "Gopi", "Krishna", "Rama", "Partha"};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is:\n");
    for (int i = 0; i < n; i++)
        printf("%s \n", arr[i]);
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array in Dictionary Order:\n");
    for (int i = 0; i < n; i++)
        printf("%s \n", arr[i]);
    return 0;
}

// Output:
// Given array is:
// Srinivas Lakshmi Gopi Krishna Rama Partha
// Sorted array in Dictionary Order:
// Gopi Krishna Lakshmi Partha Rama Srinivas
