#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	// you should probably also add some code to prevent dividing by zero...
	if (a.second != 0 && b.second != 0)
		return (static_cast<double>(a.second) / a.first) > (static_cast<double>(b.second) / b.first);
	else
		return false;
}

pair<int, vector<int>> knapsack(int W, vector<pair<int, int>> x)
{
	//Sort by their ratios
	sort(x.begin(), x.end(), &cmp);

	for (pair<int, int> t : x)
	{
		cout << "(" << t.first << "," << t.second << "), ";
	}

	int V = 0, n = x.size();
	vector<int> A = vector<int>(n, 0);

	for (int i = 0; i < n; i++)
	{
		if (W == 0)
			return pair<int, vector<int>>(V, A);
		int a = min(x.at(i).first, W);
		V += a * (x.at(i).second / x.at(i).first);
		x.at(i).first -= a;
		A[i] += a;
		W -= a;
	}
	return pair<int, vector<int>>(V, A);
}

int main()
{
	vector<pair<int, int>> x = vector<pair<int, int>>({{4, 20}, {3, 18}, {2, 14}});
	pair<int, vector<int>> value_weights = knapsack(7, x);
	cout << "Max Value = " << value_weights.first << endl;
	for (int t : value_weights.second)
	{
		cout << t << " ";
	}
}
