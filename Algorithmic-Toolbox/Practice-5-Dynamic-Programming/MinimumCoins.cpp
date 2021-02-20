#include <iostream>
#include <vector>
using namespace std;

int minimumCoins(long money, vector<int> coins)
{
    vector<int> minNumCoins = vector<int>(0);
    for (int m = 1; m <= money; m++)
    {
        minNumCoins.push_back(100000);
        int numOfCoins = 0;

        for (int i = 0; i < coins.size(); i++)
        {
            if (m >= coins.at(i))
            {
                numOfCoins = minNumCoins.at(m - coins.at(i)) + 1;
                if (numOfCoins < minNumCoins.at(m))
                    minNumCoins[m] = numOfCoins;
            }
        }
    }

    return minNumCoins.at(money);
}

int main()
{
    vector<int> coins = vector<int>({6, 5, 1});
    long money = 9;
    int minNumCoins = minimumCoins(money, coins);
    cout << "Min: " << minimumCoins;
    return 0;
}
