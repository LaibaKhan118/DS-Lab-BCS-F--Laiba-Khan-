#include <iostream>
using namespace std;

// =============== Bubble Sort

//------ Iteratively
void bubbleSort(int *arr, int size)
{
    bool swapped = true;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
//------ Recursively
void rBubbleSort(int *arr, int size)
{
    if (size == 1)
        return;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    rBubbleSort(arr, size - 1);
}

// =============== Insertion Sort

//------ Iteratively
void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//------ Recursively
void rInsertionSort(int *arr, int size)
{
    if (size <= 1)
        return;
    rInsrtionSort(arr, size - 1);
    int last = arr[size - 1];
    int j = size - 2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

// =============== Selection Sort

//------ Iteratively
void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}
//------ Recursively
void rSelectionSort(int *arr, int s, int size)
{
    if (s >= size - 1)
    {
        return;
    }
    int min_idx = s;
    for (int i = s + 1; i < size; i++)
    {
        if (arr[i] < arr[min_idx])
        {
            min_idx = i;
        }
    }
    swap(arr[s], arr[min_idx]);
    rSelectionSort(arr, s + 1, size);
}

// =============== Comb Sort

//------ Iteratively
void combSort(int *arr, int size)
{
    int gap = size;
    float shrink = 1.3;
    bool swapped = true;
    while (swapped || gap != 1)
    {
        gap = ((gap / shrink) < 1.0) ? 1 : (gap / shrink);
        swapped = false;

        int i = 0;
        while (i + gap < size)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
            i++;
        }
    }
}
//------ Recursively
void rCombSort(int *arr, int size, int gap, bool swapped, float shrink = 1.3)
{
    if (gap == 1 && !swapped)
        return;

    gap = (int)(gap / shrink);
    if (gap < 1)
        gap = 1;

    swapped = false;

    for (int i = 0; i + gap < size; i++)
    {
        if (arr[i] > arr[i + gap])
        {
            swap(arr[i], arr[i + gap]);
            swapped = true;
        }
    }
    rCombSort(arr, size, gap, swapped, shrink);
}

// =============== Shell Sort

//------ Iteratively
void shellSortIterative(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

//------ Recursively
void rShellSort(int *arr, int n, int gap)
{
    if (gap == 0)
        return;
    for (int i = gap; i < n; i++)
    {
        int temp = arr[i];
        int j = i;

        while (j >= gap && arr[j - gap] > temp)
        {
            arr[j] = arr[j - gap];
            j -= gap;
        }
        arr[j] = temp;
    }
    rShellSort(arr, n, gap / 2);
}

void rShellSortStart(int *arr, int n)
{
    int gap = n / 2;
    rShellSort(arr, n, gap);
}

// =============== Radix Sort

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int *output = new int[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

//------ Iteratively
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

//------ Recursively
void radixSortRecursive(int arr[], int n, int exp, int maxVal)
{
    if (maxVal / exp == 0)
        return;
    countSort(arr, n, exp);
    radixSortRecursive(arr, n, exp * 10, maxVal);
}
//******* For vectors, replace int* arr to vector<int>& arr, and size could calculated with arr.size() instead of bein passed as parameter

