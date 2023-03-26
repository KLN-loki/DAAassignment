// 2. Sort the strings ("Srinivas", "Lakshmi",  "Gopi", "Krishna", "Rama", "Partha")  in dictionary order using Selection Sort, Insertion Sort, Merge Sort and Quick Sort.




// Quick sort
#include<stdio.h> 
#include<string.h> 
  
void swap(char *x, char *y) 
{ 
    char temp[20]; 
    strcpy(temp, x); 
    strcpy(x, y); 
    strcpy(y, temp); 
} 
  
int partition (char arr[][20], int low, int high) 
{ 
    char pivot[20]; 
    strcpy(pivot, arr[high]); 
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (strcmp(arr[j], pivot) < 0) 
        { 
            i++;   
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
void quickSort(char arr[][20], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
int main() 
{ 
    char arr[6][20] = {"Srinivas", "Lakshmi", "Gopi", "Krishna", "Rama", "Partha"}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is:\n"); 
    for (int i=0; i < n; i++) 
        printf("%s ", arr[i]); 
  
    quickSort(arr, 0, n-1); 
  
    printf("\nSorted array in Dictionary Order:\n"); 
    for (int i=0; i < n; i++) 
        printf("%s ", arr[i]); 
    return 0; 
}

// Output:
// Given array is:
// Srinivas 
// Lakshmi 
// Gopi 
// Krishna 
// Rama 
// Partha

// Sorted array in Dictionary Order:
// Gopi 
// Krishna 
// Lakshmi 
// Partha 
// Rama 
// Srinivas
