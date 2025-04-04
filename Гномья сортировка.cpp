void gnomeSort(int* arr, int n) {
    int i = 1;  // Текущая позиция "гнома"
    
    while (i < n) {
        if (i == 0 || arr[i] >= arr[i - 1]) {
            i++;  // Идём вперёд, если порядок правильный
        } else {
            std::swap(arr[i], arr[i - 1]);  // Меняем местами и отступаем
            i--;
        }
    }
}