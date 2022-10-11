#include <iostream>
using namespace std;

// Top To Bottom Approach
int wineProfit(int wines[], int dp[][100], int i, int j, int year){
    //Base case
    if(i > j){
        return 0;
    }

    //Recursive case
    if(dp[i][j] != 0){
        return dp[i][j];
    }
    int startElement = wines[i]*year + wineProfit(wines, dp, i+1, j, year+1);
    int endElement = wines[j]*year + wineProfit(wines, dp, i, j-1, year+1);

    return dp[i][j] = max(startElement, endElement);
}



int main()
{
    int n;
    int wines[] = {2, 3, 5, 1, 4};
    int dp[100][100] = {0};
    
    int size = sizeof(wines) / sizeof(int);

    cout<<wineProfit(wines, dp, 0, size-1, 1);

   
    return 0;
}