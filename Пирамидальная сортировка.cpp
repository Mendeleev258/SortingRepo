// Просеивание элемента вниз (heapify)
void heapify(int* arr, int n, int i) {
    int largest = i;        // Инициализируем наибольший как корень
    int left = 2 * i + 1;   // Левый потомок
    int right = 2 * i + 2;  // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый потомок больше текущего наибольшего
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Рекурсивно просеиваем поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция пирамидальной сортировки
void heapSort(int* arr, int n) {
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);
        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}