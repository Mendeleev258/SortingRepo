#include <iostream>
#include <climits>

// Функция для получения k-го бита числа
int getBit(int num, int k) {
    return (num >> k) & 1;
}

// Основная функция сортировки
void radixExchangeSort(int* arr, int left, int right, int bit) {
    if (left >= right || bit < 0) return;

    int i = left;
    int j = right;

    // Разделение по текущему биту
    while (i <= j) {
        while (i <= j && getBit(arr[i], bit) == 0) i++;
        while (i <= j && getBit(arr[j], bit) == 1) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Рекурсивная сортировка подмассивов
    radixExchangeSort(arr, left, j, bit - 1);
    radixExchangeSort(arr, i, right, bit - 1);
}

// Обёртка для вызова
void radixSort(int* arr, int n) {
    const int bits = sizeof(int) * CHAR_BIT - 1; // 31 бит для int
    radixExchangeSort(arr, 0, n - 1, bits);
}