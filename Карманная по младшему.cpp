// Функция для получения разряда числа
int get_digit(int number, int digit_place)
{
    return (number / digit_place) % 10;
}
// Функция для карманной сортировки поразрядной
void counting_sort_by_digit(std::vector<int>& arr, int digit_place)
{
    const int base = 10;  
    std::vector<std::vector<int>> buckets(base); 
    for (int num : arr)
    {
        int digit = get_digit(num, digit_place);
        buckets[digit].push_back(num);
    }
    arr.clear();
    for (const std::vector<int>& bucket : buckets)
    {
        for (int num : bucket)
            arr.push_back(num);
    }
}

// Основная функция сортировки
void radix_sort(std::vector<int>& arr)
{
    int max_num = *std::max_element(arr.begin(), arr.end());
    for (int digit_place = 1; max_num / digit_place > 0; digit_place *= 10)
        counting_sort_by_digit(arr, digit_place);
}
