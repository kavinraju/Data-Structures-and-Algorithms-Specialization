#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    // you should probably also add some code to prevent dividing by zero...
    if(a.second != 0 && b.second != 0)
    	return a.second < b.second;
    else
    	return false;
}

vector<int> minimumPointsForCollection(vector<pair<int, int> > segments){
	vector<int> points;
	
	//Sort the points by right end
	sort(segments.begin(), segments.end(), &cmp);
	
	int currentPoint = segments[0].second;
	points.push_back(currentPoint);
	
	for(int i=1; i<segments.size(); i++){
		
		if(currentPoint < segments[i].first || currentPoint > segments[i].second){
			currentPoint = segments[i].second;
			points.push_back(currentPoint);
		}
	}
	
	return points;
	
}

int main(){
	
	int n; // number of segments
	cin>>n;
	
	vector<pair<int, int> > segments;
	
	for(int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		segments.push_back(pair<int, int>({a,b}));
	}
	
	vector<int> points = minimumPointsForCollection(segments);
	cout<<points.size()<<endl;
	for(int i=0; i<points.size(); i++)
		cout<<points[i]<<endl;
	
}
