#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    // you should probably also add some code to prevent dividing by zero...
    if(a.second != 0 && b.second != 0)
    	return (static_cast<double>(a.first)/a.second) > (static_cast<double>(b.first)/b.second);
    else
    	return false;
}

// vector<pair<int, int> > -> values, weigth
double knapsack(int maxBagWeigth, vector<pair<int, int> > x){
	//Sort by their ratios
	sort(x.begin(), x.end(), &cmp);
	
/*	for(pair<int, int> t: x){
		    cout<<"("<<t.first<<","<<t.second<<"), ";
	}*/
		
	int numberOfItems = x.size();
	double value = 0.0;
	//vector<int> A = vector<int>(n, 0);
	
	for(int i=0; i<numberOfItems; i++){
		if(maxBagWeigth == 0)
			return value;
		double a = (double) min(x.at(i).second, maxBagWeigth);
		value += a * ( (double) x.at(i).first / (double) x.at(i).second);
		//cout<<" (x.at(i).first / x.at(i).second): "<< (x.at(i).first / x.at(i).second)<<endl;
		x.at(i).first -= a;
		//A[i] += a;
		maxBagWeigth -= a;
	}
	
	return value;
}

int main(){
	int numberOfItems;
	int maxBagWeigth;
	vector<pair<int, int> > x;
	//https://stackoverflow.com/questions/20135901/c-cout-double-not-printing-decimal-places
	//std::cout << "default precision is " << std::cout.precision() << std::endl;
	cout<<fixed;
	cin>>numberOfItems>>maxBagWeigth;
	
	for(int i=0; i<numberOfItems; i++){
		int a, b;	
		cin>>a>>b;
		x.push_back(pair<int, int>( { a , b } ));
	}
	double value = knapsack(maxBagWeigth, x);
	cout<<setprecision(4)<<value<<endl;
}







