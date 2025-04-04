void barrierBubbleSort(int* arr, int size)
{
	int bound = size;
	do
	{
		int t = bound;
		bound = -1;
		for (int i = 0; i < t - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
				bound = i + 1;	
			}
		}
	} while (bound != -1);
}