#include <iostream>

void quick_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int i = left, j = right;
		while (i < j)
		{
			while (i < j && arr[i] < arr[j])
				--j;
			std::swap(arr[i], arr[j]);
			while (i < j && arr[j] >= arr[i])
				++i;
			std::swap(arr[i], arr[j]);
		}
		quick_sort(arr, left, i - 1);
		quick_sort(arr, j + 1, right);
	}
}