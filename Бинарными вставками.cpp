// Бинарными вставками
int binarySearch(int* arr, int key, int low, int high) 
{ 
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid]) return mid + 1;
        else if (key > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(int* arr, int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);
        for (int j = i - 1; j >= pos; j--)
            arr[j + 1] = arr[j];
        arr[pos] = key;
    }
}