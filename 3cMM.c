#include <stdio.h>
#include <string.h>

struct Flight
{
    int FlightNo;
    int DepartureTime;
    char Destination[20];
};

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
        if (L[i].DepartureTime <= R[j].DepartureTime)
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

void mergeString(struct Flight arr[], int l, int m, int r)
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

void mergeStringSort(struct Flight arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeStringSort(arr, l, m);
        mergeStringSort(arr, m + 1, r);
        mergeString(arr, l, m, r);
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

    mergeSort(arr, 0, n - 1);
    mergeStringSort(arr, 0, n - 1);

    printf("The Sorted Flight Table is : \n");
    PrintFlight(arr, 5);
    return 0;
}