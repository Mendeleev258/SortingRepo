#include <iostream>
#include <time.h>


void sheker_sort(int* mass, int s) {
    int left = 0;
    int right = s - 1;
    bool flag = true;
    while (left < right && flag) {
        bool flag = false;
        for (int i = left; i < right; i++) {
            if (mass[i] > mass[i + 1]) {
                std::swap(mass[i], mass[i + 1]);
                flag = true;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (mass[i] < mass[i - 1]) {
                std::swap(mass[i], mass[i - 1]);
                flag = true;
            }
        }
        left++;
    }
}


int main()
{
    const int SIZE = 5;
    int m[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {
        m[i]=rand()%100;
        std::cout << m[i]<<" ";
    }
    std::cout << '\n';

    sheker_sort(m, SIZE);

    for (int i = 0; i < SIZE; i++)
        std::cout << m[i]<<" ";
    return 0;
}


