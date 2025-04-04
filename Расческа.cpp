void combSort(int* arr, int size) {
    int gap = size;
    bool swapped = true;
    
    while (gap != 1 || swapped) {
        // Уменьшаем шаг с фактором ~1.3
        gap = std::max(1, (int)(gap / 1.3));
        
        swapped = false;
        
        // Проходим по массиву с текущим шагом
        for (int i = 0; i < size - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
