#include <iostream>
using namespace std;

int LIS(int arr[], int size){
    int dp[size] = {0};
    dp[0] = 1;

    int longestSoFar = 0;
    for(int i=1; i < size; i++){
        int currLongest = 0;
        for(int j=0; j < i; j++){
           
            if(arr[j] < arr[i]){
                currLongest = max(dp[j], currLongest);
            }
        }
        longestSoFar = max(currLongest+1, longestSoFar);
        dp[i] = currLongest + 1;
    }
  
    return longestSoFar;
}


int main()
{
    int arr[] = {1, 5, 2, 3, 4, 9, 6, 10};

    int size = sizeof(arr) / sizeof(int);

    cout<<LIS(arr, size);

   
    return 0;
}