void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) 
                min_idx = j;
        }
        std::swap(arr[i], arr[min_idx]);
    }
}