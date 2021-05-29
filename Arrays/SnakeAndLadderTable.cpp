#include <iostream>
using namespace std;

/**
Snakes And Ladders

Can we come up with a function which can accept m and n as inputs and print the numbers in a specific order. Use Snakes and Ladders board as an analogy of how the  number would appear. 
The expectation here is not to use any extra data structures or incur more space complexity. 

Examples

Input = 3 * 3

Output To be printed
 7 8 9
 6 5 4
 1 2 3


Input = 4 * 4

Output To be printed
16 15 14 13 - even starts at left
 9 10 11 12
 8 7 6 5
 1 2 3 4
 
 **/

int main()
{
    int n, m;
    cin >> n >> m;
    //n = 3, m =4;
    int N = n * n;
    int i = 0, j =0;
    bool isEven = n % 2 == 0;

    if(isEven) 
        j = 0; 
    else 
        j = n;

    while(i < n){
        if(j == 0){
            //j = 0, 1, 2, 3, 4
            //16, 15, 14, 13
            while(j <= n-1){
                cout<<N--<<"\t";
                //N -= (j+1);
                j++;
            }
        }else if( j == n ){
            // j = 4, 3, 2, 1, 0
            // jj = 3, 2, 1, 0 | 2, 1, 0 | 1, 0 | 0
            N -= (n-1);
            j =0;
            while(j <= n-1){
                cout<<N++<<"\t";
                //N -= (j+1);
                j++;
            }
            j = 0;
            N -= (n+1);
        }

        i++;
        cout<<endl;
    }
    return 0;
}