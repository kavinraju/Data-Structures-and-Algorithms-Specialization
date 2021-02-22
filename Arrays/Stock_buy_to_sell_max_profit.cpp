#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/stock-buy-sell/

/**
Time Complexity: O(n) 
Auxiliary Space: O(n) 
*/
vector<pair<int, int>> findStockInvestmentDays(int arr[], int n)
{
    // Create a pair<int,int> to store <buy,sell> day values
    vector<pair<int, int>> stockDays;

    for (int i = 0; i < n - 1; i++)
    {
        int stockInDay = arr[i];

        // Iterate untill the sell day is obtained
        while (i < n && arr[i] <= arr[i + 1])
            i++;

        int stockOutDay = arr[i];

        // Add the buy,sell days only if the stockInDay is less than stockOutDay
        if (stockInDay < stockOutDay)
            stockDays.push_back(pair<int, int>(stockInDay, stockOutDay));
        //cout << "Buy: " << stockInDay << " Sell: " << stockOutDay<< endl;
    }

    return stockDays;
}

/**
Time Complexity: O(n) 
Auxiliary Space: O(1) 
*/
int maxProfit(int arr[], int n)
{
    if (n == 0)
        return 0;
    int profit = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int stockInDay = arr[i];

        // Iterate untill the sell day is obtained
        while (i < n && arr[i] <= arr[i + 1])
            i++;

        int stockOutDay = arr[i];

        // Add the buy,sell days only if the stockInDay is less than stockOutDay
        if (stockInDay < stockOutDay)
            profit += (stockOutDay - stockInDay);
    }
    return profit;
}

int main()
{
    // arr is the stock cost for each day
    int arr[] = { 100, 180, 260, 310, 40, 535, 695 };
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int, int>> stockDays = findStockInvestmentDays(arr, n);

    if (stockDays.size() > 0)

        for (int i = 0; i < stockDays.size(); i++)
            cout << "Buy: " << stockDays[i].first << " Sell: " << stockDays[i].second << endl;
    else
        cout << "It's not profitable to invest with this cost slab.";

    cout << "Max profit = " << maxProfit(arr, n);
    return 0;
}
