#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
	Problem statement can be found here: 
	https://github.com/anoubhav/Coursera-Algorithmic-Toolbox/blob/master/Assignments/week3_greedy_algorithms.pdf
*/
long maxAdRevenue(int totalNumberOfAdSlots, vector<int> profitPerClickOfTheSlots, vector<int> averageNumOfClicksPerDay){
	long revenue = 0;
	
	// Sort the profitPerClickOfTheSlots and averageNumOfClicksPerDay
	sort(profitPerClickOfTheSlots.begin(), profitPerClickOfTheSlots.end());
	sort(averageNumOfClicksPerDay.begin(), averageNumOfClicksPerDay.end());
	
	for(int i=0; i<totalNumberOfAdSlots; i++){
		revenue += 	(long) profitPerClickOfTheSlots[i] * averageNumOfClicksPerDay[i]; 
		/*
		Failed case #10/41: Wrong answer: Resolved this error by type casting 
		profitPerClickOfTheSlots[i] * averageNumOfClicksPerDay[i] to long */

		//cout<<"("<<profitPerClickOfTheSlots[i]<<","<<averageNumOfClicksPerDay[i]<<"), ";
	}
	
	//cout<<revenue;
	return revenue;
}

int main(){
	int totalNumberOfAdSlots;
	
	cin>>totalNumberOfAdSlots;
	
	vector<int> profitPerClickOfTheSlots, averageNumOfClicksPerDay;
	
	for(int i=0; i<totalNumberOfAdSlots; i++){
		int t;
		cin>>t;
		profitPerClickOfTheSlots.push_back(t);
	}
	
	for(int i=0; i<totalNumberOfAdSlots; i++){
		int t;
		cin>>t;
		averageNumOfClicksPerDay.push_back(t);
	}
	
	cout<<maxAdRevenue(totalNumberOfAdSlots, profitPerClickOfTheSlots, averageNumOfClicksPerDay);
	
	return 0;
}
