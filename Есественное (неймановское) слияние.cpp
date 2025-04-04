// Слияние двух серий
void merge(int* arr, int* temp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    
    while (i < mid && j < right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    // Дописываем оставшиеся элементы
    while (i < mid) temp[k++] = arr[i++];
    while (j < right) temp[k++] = arr[j++];
    
    // Копируем обратно в исходный массив
    for (int p = left; p < right; p++) {
        arr[p] = temp[p];
    }
}

// Поиск границ серий
int findNextRun(int* arr, int n, int pos) {
    if (pos >= n - 1) return n;
    
    int i = pos;
    // Возрастающая серия
    while (i < n - 1 && arr[i] <= arr[i + 1]) i++;
    // Убывающая серия (разворачиваем)
    while (i < n - 1 && arr[i] >= arr[i + 1]) i++;
    
    return i + 1;
}

// Основная функция сортировки
void naturalMergeSort(int* arr, int n) {
    if (n <= 1) return;
    
    int* temp = new int[n];
    bool sorted = false;
    
    while (!sorted) {
        sorted = true;
        int left = 0, mid = 0, right = 0;
        
        while (left < n) {
            mid = findNextRun(arr, n, left);
            if (mid >= n) break;
            
            right = findNextRun(arr, n, mid);
            merge(arr, temp, left, mid, right);
            
            if (right < n) sorted = false;
            left = right;
        }
    }
    
    delete[] temp;
}
