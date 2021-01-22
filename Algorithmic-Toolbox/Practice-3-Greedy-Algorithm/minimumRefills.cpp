#include<iostream>
using namespace std;


int minRefills(int x[], int n, int L){
	int numRefills = 0, currentRefill = 0;
	while(currentRefill <= n){
		int lastRefill = currentRefill;
		
		while(currentRefill <= n && x[currentRefill + 1] - x[lastRefill] <= L)
			currentRefill += 1;
		
		if(currentRefill == lastRefill)
			return -1;
		
		if(currentRefill <= n)
			numRefills += 1;
	}
	
	return numRefills;
}

int main(){
	//int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
	//int n = 7;
	//int L = 3;
	int n, L;
	cin>>n>>L;
	int a[n+1];
	a[0] = 0;
	for(int i=1; i<n+1; i++){
		cin>>a[i];
	}
	int numRefills = minRefills(a, n, L);
	if(numRefills == -1 )
		cout<<"NOT POSSIBLE";
	else
		cout<<"minRefills = "<<numRefills;
	return 0;
}
