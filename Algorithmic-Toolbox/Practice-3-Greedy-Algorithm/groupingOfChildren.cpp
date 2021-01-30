#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// This function returns the number of groups, minimum number of groups
int pointsCoveredSorted(vector<float> x, int n)
{
	//vector<vector<int>> R;
	int R = 0;
	int i = 0;
	while (i < n)
	{
		int l = x.at(i), r = x.at(i) + 1;
		R += 1;
		i += 1;
		while (i < n && x.at(i) <= r)
		{
			i += 1;
		}
	}
	return R;
}

// This function returns the number of groups
vector<vector<float>> getGroupings(vector<float> x, int n)
{
	vector<vector<float>> R;
	int i = 0, j = 0;
	while (i < n)
	{
		int l = x.at(i), r = x.at(i) + 1;
		R.push_back(vector<float>({x.at(i)}));
		i += 1;
		while (i < n && x.at(i) <= r)
		{
			R.at(j).push_back(x.at(i));
			i += 1;
		}
		j++;
	}
	return R;
}

int main()
{
	vector<float> childrenAges;
	cout << "Number of children: ";
	int t;
	cin >> t;
	cout << "Enter the ages of children: " << endl;
	for (int i = 0; i < t; i++)
	{
		float x;
		cin >> x;
		childrenAges.push_back(x);
	}

	sort(childrenAges.begin(), childrenAges.end());
	cout << "Number of groups(minimum number of groups): " << pointsCoveredSorted(childrenAges, childrenAges.size()) << endl;

	vector<vector<float>> groupList = getGroupings(childrenAges, childrenAges.size());
	/*for(int i=0; i<groupList.size();i++){
		copy(groupList.at(i).begin(), groupList.at(i).end(), ostream_iterator<vector<float> >(cout, "\n"));
	}*/

	for (int j = 0; j < groupList.size(); j++)
	{
		cout << "Group " << j + 1 << endl;
		for (std::vector<float>::const_iterator i = groupList.at(j).begin(); i != groupList.at(j).end(); ++i)
			std::cout << *i << ' ';
		cout << endl;
	}

	return 0;
}
