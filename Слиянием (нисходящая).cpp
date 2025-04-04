// Слияние двух отсортированных подмассивов
// Левый подмассив a[begin..middle-1]
// Правый подмассив a[middle..end-1]
// Результат записывается в b[begin..end-1]
void Merge(int a[], size_t begin, size_t middle, size_t end, int b[]) 
{
    size_t i = begin, j = middle;
    for (size_t k = begin; k < end; ++k) {
        if (i < middle && (j >= end || a[i] <= a[j])) {
            b[k] = a[i];
            i++;
        }
        else {
            b[k] = a[j];
            j++;
        }
    }
}

// Копирование элементов из одного массива в другой
void CopyArray(int a[], size_t begin, size_t end, int b[]) 
{
    for (size_t k = begin; k < end; ++k) 
        b[k] = a[k];
}

// Рекурсивная функция сортировки слиянием
void TopDownSplitMerge(int a[], size_t begin, size_t end, int b[])
{
    if (end - begin <= 1) // Базовый случай - массив из 1 элемента
        return;
    
    size_t middle = begin + (end - begin) / 2;
    
    // Рекурсивно сортируем обе половины
    TopDownSplitMerge(a, begin, middle, b);
    TopDownSplitMerge(a, middle, end, b);
    
    // Сливаем отсортированные половины
    Merge(a, begin, middle, end, b);
    
    // Копируем результат обратно в исходный массив
    CopyArray(b, begin, end, a);
}

// Основная функция нисходящей сортировки слиянием
void TopDownMergeSort(int a[], int b[], size_t n)
{
    TopDownSplitMerge(a, 0, n, b);
}