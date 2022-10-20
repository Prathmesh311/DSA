class Solution {
public:
    
    int coinChange2(vector<int>& coins, int dp[][5001], int i, int amount){
        //Base case
        if( amount == 0){
           
            return 1;
        }
        
        if(i >= coins.size()){
            return 0;
        }
      
        
        if(dp[i][amount] != 0){
            return dp[i][amount];
        }
        
        //Recursive case
        int inc=0;
        int exc=0;
        
        if(amount - coins[i] >= 0){
             
            inc = coinChange2(coins, dp, i, amount - coins[i]);
            exc = coinChange2(coins, dp, i+1, amount);
            return dp[i][amount] = inc + exc;
               
        }else{
            exc = coinChange2(coins, dp, i+1, amount);
            return dp[i][amount] = inc + exc;
        }
      
        
    }
    
    int change(int amount, vector<int>& coins) {
        int dp[301][5001] = {0};
       
        return coinChange2(coins, dp, 0, amount);
    }
};
