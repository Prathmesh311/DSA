#include <iostream>
using namespace std;

//Bottom Up Appraoch
int maxSum(int arr[],int n){
    int dp[100]= {0};

    //Exclude 1st element if it's -ve
    dp[0] = dp[0]>0?dp[0]:0;
    int maxSoFar = dp[0];

    for(int i=1; i < n; i++){
        dp[i] = dp[i-1] + arr[i];

        //If sum goes into -ve set it as 0
        if(dp[i] < 0){
            dp[i] = 0;
        }

        maxSoFar = max(dp[i], maxSoFar);
    }

    return maxSoFar;
}


int main()
{
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};

    int size = sizeof(arr) / sizeof(int);

    cout<<maxSum(arr, size);

   
    return 0;
}