class Solution {
public:
    int findChange(vector<int> &coins, vector<vector<int>> &dp, int amount, int index){
        if(amount == 0){
            return 0;
        }

        if(index >= coins.size() || amount < 0){
            return 100001;
        }

        if(dp[index][amount] != INT_MAX){
            return dp[index][amount];
        }

        int minChange = 100001;
        for(int i=index; i < coins.size(); i++){
            minChange = min(minChange, findChange(coins, dp, amount - coins[i], i) + 1);
        }

        return dp[index][amount] = minChange;
    }

    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, INT_MAX));
        // int result = findChange(coins, dp, amount, 0); 
        // return result >= 10001 ? -1 : result;

        vector<int> dp(amount+1, 100001);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }

        return dp[amount] >= 10001 ? -1 : dp[amount];
    }
};
