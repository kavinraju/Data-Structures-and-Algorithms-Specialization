#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void merge(int *a, int start, int mid, int end)
{

	if (a[mid - 1] <= a[mid])
		return;

	int i = start;
	int j = mid;
	int tempIndex = 0;
	int temp[end - start]; // Create a temp array to store the sorted elements.

	while (i < mid && j < end)
		temp[tempIndex++] = a[i] <= a[j] ? a[i++] : a[j++]; // Compare and store the elements into temp[]

	// Copy the remaining elements into temp[] from the first half
	while (i < mid)
	{
		temp[tempIndex++] = a[i++];
	}

	// Copy the remaining elements into temp[] from the second half
	while (j < end)
	{
		temp[tempIndex++] = a[j++];
	}

	// Reset the tempIndex and i to its initial positions
	tempIndex = 0;
	i = start;

	// Copy back the sorted elements stored in temp[] into the original array a[]
	while (i < end)
	{
		a[i++] = temp[tempIndex++];
	}
}

void mergeSort(int *a, int start, int end)
{

	if (end - start < 2)
		return;

	int mid = (start + end) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid, end);
	merge(a, start, mid, end);
}

int main()
{
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl;

	mergeSort(a, 0, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
