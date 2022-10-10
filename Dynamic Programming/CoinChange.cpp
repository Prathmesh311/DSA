#include <iostream>
using namespace std;

// Top To Bottom Approach
int coinChange(int n, int size, int coins[], int dp[])
{
    // Base case
    if (n == 0)
    {
        return 0;
    }

    // Recursive case
    //Checking data
    if(dp[n] != 0){
        return dp[n];
    }

    int minCost = INT8_MAX;
    for (int i = 0; i < size; i++)
    {
        if (n - coins[i] >= 0)
        {
            int currCost = coinChange(n - coins[i], size, coins, dp) + 1;

            if (currCost < minCost)
            {
                minCost = currCost;
            }
        }
    }

    //Memoization
    dp[n] = minCost;
    return minCost;
}

// Bottom To Top Approach
int coinChangeBT(int n, int size, int coins[]){
    int dp[n] = {INT8_MAX};
    

    dp[0] = 0;
    for(int j=1; j <= n; j++){
        int minCost = INT8_MAX;
        for(int i=0; i < size; i++){
            if(j - coins[i] >= 0){
                int currCost = dp[j-coins[i]] + 1;

                if(currCost < minCost){
                    minCost =  currCost;
                }
            }
        }
        dp[j] = minCost;
    }

    return dp[n];
}

int main()
{
    int n;
    int coins[] = {1, 3, 5};
    int dp[100] = {0};

    cin >> n;
    int size = sizeof(coins) / sizeof(int);

    cout << coinChange(n, size, coins, dp) << endl;
    cout<<coinChangeBT(n, size, coins);
    return 0;
}