void hoor(int left, int right, int* a) //изначально left=0 и right=n-1
{
    int i = left;
    int j = right;
    int x = a[(left + right) / 2];
    do {
        while (a[i] <= x) i++;
        //поиск с левой стороны элемента большего, чем разделитель
        while (x < a[j]) j--;
        //поиск с правой стороны элемента меньшего, чем разделитель
        if (i<j) {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) hoor(left, j, a);
    //применить процедуру сортировки для левой части массива
    if (i < right) hoor(i, right, a);
    //применить процедуру сортировки для правой части массива
}