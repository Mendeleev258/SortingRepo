#include<iostream>


//Левая половина источника a[begin: middle - 1]
//Правая половина источника a[middle: end - 1]
//Результат: слияние в b[begin: end - 1]

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

void CopyArray(int a[], size_t begin, size_t end, int b[]) 
{
    for (size_t k = begin; k < end; ++k) 
        b[k] = a[k];
}

//Основной массив a[] содержит элементы для сортировки
//Массив b[] является вспомогательным

void BottomUpMergeSort(int a[], int b[], size_t n) 
{
    for (size_t width = 1; width < n; width = 2 * width) {
        for (size_t i = 0; i < n; i = i + 2 * width) {
            Merge(a, i, std::min(i + width, n), std::min(i + 2 * width, n), b);
        }
        CopyArray(b, 0, n, a); //Возвращаем b[] в a[]
        //Теперь массив a заполнен прогонами длиной 2 * width
    }
}


int main()
{
    int a[] = {2, 9, 5, 12, 10, 7, 11, 3, 8, 6, 15, 4, 1, 16, 13, 14};
    for (size_t i = 0; i < 16; ++i)
        std::cout << a[i] << ' ';
    
    int b[16] = {};
    BottomUpMergeSort(a, b, 16);

    std::cout << "\n-------------- after sorting ------------\n";
    for (size_t i = 0; i < 16; ++i)
        std::cout << a[i] << ' ';
    
    std::cin.get();
    return 0;
}