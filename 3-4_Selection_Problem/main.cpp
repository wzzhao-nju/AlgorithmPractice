#include<iostream>
using namespace std;
int selection(int a[], int start, int end, int k)
{
	int i = start, j = end, pivot = a[start];
	while (i < j)
	{
		while (i < j&&a[j] >= pivot)
			j--;
		if (i < j)
			a[i++] = a[j];
		while (i < j&&a[i] <= pivot)
			i++;
		if (i < j)
			a[j--] = a[i];
	}
	a[i] = pivot;
	if (i - start == k - 1)
		return a[i];
	else if (i - start < k - 1)
		return selection(a, i + 1, end, k - 1 - i + start);
	else
		return selection(a, start, i - 1, k);
}
int main()
{
	int n, k;
	cin >> n >> k;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << selection(a, 0, n - 1, k) << endl;
	return 0;
}