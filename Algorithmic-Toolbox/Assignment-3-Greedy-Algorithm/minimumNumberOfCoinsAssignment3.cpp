#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include <functional>
using namespace std;

int minNumberOfCoins(int n){
	int deno[] = {1,5,10};
	int m = sizeof(deno) / sizeof(deno[0]); 
	sort(deno, deno + m, greater<int>()); 
	
	int coins = 0;
	int i = 0;
	while(n>0){
		while(n/deno[i] > 0){
			int c = n/deno[i];
			coins += c;
			n -= c * deno[i];
			i++;
		}
		if(n/deno[i] == 0)
			i++;
	}
	return coins;
}

int main(){
	int n;
	cin>>n;
	cout<<minNumberOfCoins(n);
	return 0;
}
