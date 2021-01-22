#include<iostream>
using namespace std;


int minRefills(int x[], int totalFuelPoints, int thresholdDistanceOfFuel){
	int numRefills = 0, currentRefill = 0;
	
	while(currentRefill <= totalFuelPoints){
		int lastRefill = currentRefill;
			
		while(currentRefill <= totalFuelPoints && x[currentRefill + 1] - x[lastRefill] <= thresholdDistanceOfFuel)
			currentRefill += 1;
		
		if(currentRefill == lastRefill)
			return -1;
		
		if(currentRefill <= totalFuelPoints)
			numRefills += 1;
	}
	
	return numRefills;
}

int main(){
	//int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
	//int n = 7;
	//int L = 3;
	int totalKMs, thresholdDistanceOfFuel, totalFuelPoints;
	cin>>totalKMs>>thresholdDistanceOfFuel>>totalFuelPoints;
	int a[totalFuelPoints+2];
	a[0] = 0;
	for(int i=1; i<=totalFuelPoints; i++){
		cin>>a[i];
	}
	
	a[totalFuelPoints+1] = totalKMs;

	int numRefills = minRefills(a, totalFuelPoints, thresholdDistanceOfFuel);
	cout<<numRefills;
	return 0;
}
