// 3. Assume that there is a database table consisting of flight details like Flight No, Departure Time, and Destination as below:
//      1    11     Delhi
//      2    10     Mumbai
//      3    13     Delhi
//      4    9      Mumbai
//      5    12     Mumbai
//  We would like to sort the above table first by Departure Time and then the resultant table should be sorted by Destination resulting in the following table:
//        1    11     Delhi
//        3    13     Delhi
//        4    9      Mumbai
//        2    10     Mumbai
//        5    12     Mumbai

// a) Apply the Merge Sort for the first sorting and Quick Sort for the second sorting.
// b) Apply the Quick Sort for the first sorting and Merge Sort for the second sorting.

// c) Apply the Merge Sort for the first sorting and merge Sort for the second sorting.
// d) Apply the Quick Sort for the first sorting and Quick Sort for the second sorting.
// Based on the above results, draw the conclusion about the stability of the merge and quick sort algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Flight
{
    int FlightNo;
    int DepartureTime;
    char Destination[20];
};

void Merge(struct Flight f[], int low, int high, int mid)
{
    int i, j, k;
    struct Flight temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (f[i].DepartureTime < f[j].DepartureTime)
        {
            temp[k] = f[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = f[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = f[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = f[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        f[i] = temp[i - low];
    }
}

void MergeSort(struct Flight f[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(f, low, mid);
        MergeSort(f, mid + 1, high);
        Merge(f, low, high, mid);
    }
}

int Partition(struct Flight f[], int low, int high)
{
    char pivot[20];
    int i, j;
    strcpy(pivot, f[low].Destination);
    i = (high + 1);
    for (j = high; j >= low + 1; j--)
    {
        if (strcmp(f[j].Destination, pivot) >= 0)
        {
            i--;
            struct Flight temp;
            temp = f[i];
            f[i] = f[j];
            f[j] = temp;
        }
    }
    struct Flight temp;
    temp = f[i - 1];
    f[i - 1] = f[low];
    f[low] = temp;
    return (i - 1);
}

void QuickSort(struct Flight f[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(f, low, high);
        QuickSort(f, low, pi - 1);
        QuickSort(f, pi + 1, high);
    }
}

void PrintFlight(struct Flight f[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d  %d  %s\n", f[i].FlightNo, f[i].DepartureTime, f[i].Destination);
    }
}

int main()
{
    struct Flight arr[] = {{1, 11, "Delhi"}, {2, 10, "Mumbai"}, {3, 13, "Delhi"}, {4, 9, "Mumbai"}, {5, 12, "Mumbai"}};
    int n = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, n - 1);
    QuickSort(arr, 0, n - 1);

    printf("The Sorted Flight Table is : \n");
    PrintFlight(arr, n);
    return 0;
}