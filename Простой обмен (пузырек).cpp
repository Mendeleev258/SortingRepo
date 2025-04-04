void bubbleSort(int* arr, int n) 
{
    for (int i = 0; i < n - 1; i++)          // Внешний цикл (n-1 проходов)
        for (int j = 0; j < n - i - 1; j++)  // Внутренний цикл (сравнение соседей)
            if (arr[j] > arr[j + 1])         // Если порядок нарушен
                std::swap(arr[j], arr[j + 1]);// Меняем местами
} 