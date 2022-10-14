#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Not running all test cases
int MCM(int arr[], int n){
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i < n; i++){
        int r=0, c=i;
        int val = INT_MAX;
        while(c < n){
            for(int pivot = r; pivot < c; pivot++){
                val = min(val, dp[r][pivot] + dp[pivot+1][c] + arr[r]*arr[pivot]*arr[c+1]);
            }
            dp[r][c] = val;
            r++, c++;
        }
    }

    return dp[0][n-1];

}
int main()
{
    int arr[] = {1, 2, 3, 1, 3};

    int size = sizeof(arr) / sizeof(int);

    cout<<MCM(arr, size-1);

   
    return 0;
}