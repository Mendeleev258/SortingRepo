void sort_by_simple_insert(int* a, int size)
{
	auto insert = [&](int x, int size)
		{
			int j = size;
			while (j >= 0 && (a[j] > x))
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = x;
		};
	for (int i = 1; i < size; ++i)
	{
		if (a[i - 1] > a[i])
		{
			insert(a[i], i - 1);
		}
	}
}

