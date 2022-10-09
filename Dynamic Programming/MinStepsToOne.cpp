#include <iostream>
using namespace std;

//Top To Bottom Approach
int minStepsToOne(int n, int dp[]){
    //Base case
    if(n == 1){
        return 0;
    }

    //Recursive case
    //Checking in dp
    if(dp[n] != 0){
        return dp[n];
    }
    int divideByThree = INT8_MAX;
    int divideByTwo = INT8_MAX;
    int reduceByOne = INT8_MAX;

    if(n%3 == 0){
        divideByThree = minStepsToOne(n/3, dp) + 1;
    }
    if(n%2 == 0){
        divideByTwo = minStepsToOne(n/2, dp) + 1;
    }
    
    reduceByOne = minStepsToOne(n-1, dp) + 1;
    

    int ans =  min(reduceByOne, min(divideByTwo, divideByThree));
    dp[n] = ans;
    return ans;

}


//Bottom To Top Approach
int minStepsToOneBT(int n){
    int dp[100] = {INT8_MAX};

    dp[1] = 0;
    dp[0] = 0;

    int divideByThree = INT8_MAX;
    int divideByTwo = INT8_MAX;
    int reduceByOne = INT8_MAX;

    for(int i=2; i <= n; i++){
        if(i%3 == 0){
            divideByThree = dp[i/3];
        }
        if(i%2 == 0){
            divideByTwo = dp[i/2];
        }
        reduceByOne = dp[i-1];

        dp[i] = min(reduceByOne, min(divideByThree, divideByTwo)) + 1;
        //cout<<min(reduceByOne, min(divideByThree, divideByTwo))<<" ";
    }
  

    return dp[n];

}

int main() {
    int n;
    int dp[100] = {0};

    cin>>n;
    
    
    cout<<minStepsToOne(n, dp)<<endl;
    cout<<minStepsToOneBT(n);
    return 0;
}