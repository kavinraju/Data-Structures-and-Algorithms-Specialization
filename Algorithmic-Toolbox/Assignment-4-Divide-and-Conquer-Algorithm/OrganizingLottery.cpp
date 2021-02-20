#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
    return a.first < b.first;
}

int binarySearch(vector<pair<long long, long long>> segments, long long searchItem)
{
    int count = 0, start = 0, mid, end = segments.size() - 1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (segments.at(mid).first <= searchItem && segments.at(mid).second >= searchItem)
        {
            count++;
            end = mid - 1;
        }
        else if (searchItem < segments.at(mid).first)
        {
            end = mid - 1;
        }
        else if (searchItem > segments.at(mid).first)
        {
            start = mid + 1;
        }
    }

    return count;
}

vector<int> organizeLottery(vector<pair<long long, long long>> segments, vector<long long> points)
{
    vector<int> lotteryPoints;

    sort(segments.begin(), segments.end(), &cmp);
    int p = 0;
    while (p < points.size())
    {
        int searchPoint = points.at(p);

        // Do binary search
        lotteryPoints.push_back(binarySearch(segments, searchPoint));
        p++;
    }

    return lotteryPoints;
}

int main()
{
    int numOfSegments, numOfPoints;
    cin >> numOfSegments >> numOfPoints;

	if(! ((numOfSegments >= 1 && numOfSegments<= 50000) || (numOfPoints >= 1 && numOfPoints<= 50000)) )
		return 0;
		
    vector<pair<long long, long long>> segments;
    vector<long long> points;

    for (int i = 0; i < numOfSegments; i++)
    {
        long long a, b;
        cin >> a >> b;
        segments.push_back(pair<long long, long long>({a, b}));
    }

    for (int i = 0; i < numOfPoints; i++)
    {
        long long a;
        cin >> a;
        points.push_back(a);
    }

    vector<int> lottery = organizeLottery(segments, points);

    for (int i = 0; i < lottery.size(); i++)
        cout << lottery.at(i) << " ";
    return 0;
}
