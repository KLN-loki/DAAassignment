
#include <stdio.h>
#include <string.h>

struct flight
{
    int no;
    int time;
    char destination[20];
};

void swap(struct flight *x, struct flight *y)
{
    struct flight temp = *x;
    *x = *y;
    *y = temp;
}

int partition(struct flight arr[], int low, int high)
{
    int pivot = arr[high].time;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].time <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct flight arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition2(struct flight arr[], int low, int high)
{
    int pivot = arr[high].destination[0];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].destination[0] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort2(struct flight arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition2(arr, low, high);
        quickSort2(arr, low, pi - 1);
        quickSort2(arr, pi + 1, high);
    }
}

void PrintFlight(struct flight f[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d  %d  %s\n", f[i].no, f[i].time, f[i].destination);
    }
}

int main()
{
    struct flight arr[] = {{1, 11, "Delhi"}, {2, 10, "Mumbai"}, {3, 13, "Delhi"}, {4, 9, "Mumbai"}, {5, 12, "Mumbai"}};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    quickSort2(arr, 0, n - 1);

    printf("The Sorted Flight Table is : \n");
    PrintFlight(arr, n);
    return 0;
}