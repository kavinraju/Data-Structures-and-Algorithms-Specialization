#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int i, int minIndex){
	int temp = a[i];
	a[i] = a[minIndex];
	a[minIndex] = temp;
}

void selectionSort(int* a, int n){
	for(int i=0; i<n; i++){
		int minIndex = i;
		
		for(int j = i+1; j<n; j++){
			if(a[j] < a[minIndex])
				minIndex = j;
		}
		
		swap(a[i], a[minIndex]);
	}
	
}

int main(){
	int n;
	cin>>n;
	int a[n];
	
	for(int i = 0; i<n; i++)
		cin>>a[i];
	
	for(int i = 0; i<n; i++)
		cout<<a[i]<<" ";
	
	cout<<endl;
	
	selectionSort(a, n);
	
	for(int i = 0; i<n; i++)
		cout<<a[i]<<" ";
}
