class Solution {
public:
    int coinComb(vector<int>& coins, vector<vector<int>>& dp, int index, int amount){
        if(amount == 0){
            return 1;
        }

        if(amount < 0 || index >= coins.size()){
            return 0;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        dp[index][amount] = coinComb(coins, dp, index, amount - coins[index]) + 
                            coinComb(coins, dp, index+1, amount);

        return dp[index][amount];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(301, vector<int>(5001, -1));
        return coinComb(coins, dp, 0, amount);
    }
};
