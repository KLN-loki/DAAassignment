#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Flight
{
    int FlightNo;
    int DepartureTime;
    char Destination[20];
};

void swap(struct Flight *a, struct Flight *b)
{
    struct Flight t = *a;
    *a = *b;
    *b = t;
}

int partition(struct Flight arr[], int low, int high)
{
    int pivot = arr[high].DepartureTime;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].DepartureTime <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct Flight arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(struct Flight arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    struct Flight L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i].Destination, R[j].Destination) <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Flight arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void PrintFlight(struct Flight arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d\t%d\t%s\n", arr[i].FlightNo, arr[i].DepartureTime, arr[i].Destination);
    printf("\n");
}

int main()
{
    struct Flight arr[] = {{1, 11, "Delhi"}, {2, 10, "Mumbai"}, {3, 13, "Delhi"}, {4, 9, "Mumbai"}, {5, 12, "Mumbai"}};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    mergeSort(arr, 0, n - 1);

    printf("The Sorted Flight Table is : \n");
    PrintFlight(arr, n);
    return 0;
}