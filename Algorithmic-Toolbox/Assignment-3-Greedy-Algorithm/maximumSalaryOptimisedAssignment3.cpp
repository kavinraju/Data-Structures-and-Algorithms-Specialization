#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <sstream> // for string streams
#include <string>  // for string
using namespace std;

/*
Resolved this case:
Failed case #3/11: (Wrong answer)

Input:
100
2 8 2 3 6 4 1 1 10 6 3 3 6 1 3 8 4 6 1 10 8 4 10 4 1 3 2 3 2 6 1 5 2 9 8 5 10 8 7 9 6 4 2 6 3 8 8 9 8 2 9 10 3 10 7 5 7 1 7 5 1 4 7 6 1 10 5 4 8 4 2 7 8 1 1 7 4 1 1 9 8 6 5 9 9 3 7 6 3 10 8 10 7 2 5 1 1 9 9 5

Your output:
9910101010101010101099999998888888888887777777776666666666555555554444444443333333333222222222111111111111111
Correct output:
9999999998888888888887777777776666666666555555554444444443333333333222222222111111111111111101010101010101010
 (Time used: 0.00/1.00, memory used: 9129984/536870912.)
 
*/
bool cmp(const int &a, const int &b)
{
	return a > b;
}

int removeZeros(int n)
{
	int temp;
	while (n != 0)
	{
		temp = n / 10;
		n /= 10;
		if (n / 10 == 0)
			return temp;
	}
}

string getMaxSalary(deque<int> digits)
{
	string answer = "";

	sort(digits.begin(), digits.end(), &cmp);
	//digits.sort();
	//digits.reverse()

	/*for(int i=0 ; i<digits.size(); i++)
		cout<<digits[i]<<" ";
		
	cout<<endl;*/

	deque<int> tens;

	while (digits.size() != 0)
	{
		//cout<<"digits.size(): "<<digits.size()<<endl;
		//cout<<"answer: "<<answer<<endl;
		int maxDigit; // Note INT8_MIN

		// Separate out the all the tens, hundreds, thousands... 10,100,1000,...
		while (removeZeros(digits[0]) == 1)
		{
			tens.push_back(digits[0]);
			digits.pop_front();
		}

		maxDigit = digits[0];

		if (answer != "")
		{

			/*
			 IMPORTANT STEP - Taking the "answer" didn't work, as its length can go more than 50 or 100,
			 taking the first two digits of the answer and comparing works.
			 Eg. answer = "35892" => ans = "35" 
			 	 maxDigit = 45
			 	 => appendToFront = 4535
			 	 => appendToBack = 3545
			*/
			int ans = stoi(answer.substr(0, 2));
			//cout<<"ans: "<<ans<<endl;
			int appendToFront = stoi(to_string(maxDigit) + to_string(ans));
			int appendToEnd = stoi(to_string(ans) + to_string(maxDigit));

			//cout<<"appendToFront: "<<appendToFront<<endl;
			//cout<<"appendToEnd: "<<appendToEnd<<endl;

			if (appendToFront > appendToEnd)
				answer = to_string(maxDigit) + answer;
			else
				answer = answer + to_string(maxDigit);
		}
		else
		{
			answer = to_string(maxDigit);
		}

		//digits.erase(remove(digits.begin(), digits.end(), maxDigit), digits.end());
		digits.pop_front();
	}

	// sort the tens into increasing order..
	sort(tens.begin(), tens.end());

	//Append the tens to the answer
	for (int &i : tens)
	{
		answer += to_string(i);
	}

	return answer;
}

int main()
{
	int n;
	cin >> n;

	deque<int> digits;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		digits.push_back(t);
	}

	string maxSalary = getMaxSalary(digits);
	cout << maxSalary;
	return 0;
}
