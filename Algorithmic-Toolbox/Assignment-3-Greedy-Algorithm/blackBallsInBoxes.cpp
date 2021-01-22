//Balls in Boxes
/* Distribute N black balls among 10 boxes so that every two boxes have 
different number of balls (you can put 0 balls in some box if you want to). 
Fill in numbers of black balls in each box below.*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> blackBallsInBoxes(int numOfBalls, int numOfBoxes){
	vector<int> ballsInBoxes = vector<int>(numOfBoxes, 0);
	int N = numOfBalls;
	int mul = 1;
	int perBox = round(numOfBalls / numOfBoxes);
	cout<<"Per Box: "<<perBox<<endl;
	for(int i=0; i < numOfBoxes; i++){
		if(N == 0)
			return ballsInBoxes;
		
		int balls = perBox + mul;
		if(balls <= N)
			ballsInBoxes[i] += balls;
		
		mul *= -1;
		N -= balls;
	}
	return ballsInBoxes;
}

int main(){
	vector<int> ballsInBoxes = blackBallsInBoxes(60,10);
	for(int i=0; i< ballsInBoxes.size(); i++){
		cout<<"Box "<<i+1<<": "<<ballsInBoxes[i]<<" balls"<<endl;
	}
	cout<<"Sum: "<<accumulate(ballsInBoxes.begin(), ballsInBoxes.end(), 0);
}
