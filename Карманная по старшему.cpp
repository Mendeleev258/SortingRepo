#include <algorithm>
#include <vector>

const int BASE = 10;

void msd_radix_sort(std::vector<int>& arr, int exp)
{
	if (arr.empty() || exp == 0)
		return;
	std::vector <std::vector<int>> buckets(BASE);
	for (int num : arr)
		buckets[num / exp] % BASE].push_back(num);
	arr.clear();
	for (auto& bucket : buckets)
	{
		if (bucket.size() > 1)
			msd_radix_sort(bucket, exp / BASE);
		arr.indert(arr.end(), bucket.begin(), bucket.end());
	}
}

void radix_sort(std::vector<int>& arr)
{
	int max_val = *std::max_element(arr.begin(), arr.end());
	int exp = 1;
	while (max_val / exp >= BASE)
		exp *= BASE;
	msd_radix_sort(arr, exp);
}