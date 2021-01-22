#include<iostream>
#include<vector>
#include <algorithm>
#include<numeric>
using namespace std;

vector<int> numberOfPricesList(int numCandies){
	int n = numCandies;
	vector<int> prices;
	int i = 0;
	
	while(n > 0){
		int sum;
		if(prices.size() != 0)
			sum = accumulate(prices.begin(), prices.end(), 0);
		else
			sum = 0;
		//cout<<"Sum: "<<sum<<endl;
		if(n - sum > numCandies/2){
			prices.push_back(i+1);
			//cout<<"if: prices[i]: "<<prices[i]<<endl;	
		}else{
			prices.push_back(n);
			//cout<<"else: prices[i]: "<<prices[i]<<endl;
		}
		n -= prices[i++];
		//cout<<"n : "<<n<<endl;
	}
	
	return prices;
}
int main(){
	
	int numOfCandies;
	cin>>numOfCandies;
	
	vector<int> pricesList = numberOfPricesList(numOfCandies);
	cout<<pricesList.size()<<endl;
	for(int i=0; i<pricesList.size(); i++)
		cout<<pricesList[i]<<" ";
	
}
