#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int knapsack(int weights[], int prices[], int (&dp)[100][100],int bagSize, int n){
    //Base case
    if(bagSize == 0 || n == -1){
        return 0;
    }

    //Recursive case
    if(dp[bagSize][n] != -1){
        return dp[bagSize][n];
    }

    if(bagSize >= weights[n]){
        int include = prices[n] + knapsack(weights, prices, dp, bagSize - weights[n], n-1);
        int exclude = knapsack(weights, prices, dp, bagSize, n-1);
        return max(include, exclude);
    }

    if(bagSize < weights[n]){
        return knapsack(weights, prices, dp, bagSize, n-1);
    }

}

int main()
{
    int bagsize = 4;
    int weights[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};
    int dp[100][100];
    
    memset(dp, -1, sizeof(dp));
    int size = sizeof(weights)/sizeof(int);
    
    cout<<knapsack(weights, prices, dp, bagsize, size-1);
  
    return 0;
}