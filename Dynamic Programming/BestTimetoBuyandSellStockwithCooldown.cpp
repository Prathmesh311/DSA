class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy){
            int buyElement = - prices[i] + solve(i+1, 0, prices, dp);
            int skipBuy = 0 + solve(i+1, 1, prices, dp);
            profit = max(buyElement, skipBuy);
        }else{
            int sellElement = prices[i] + solve(i+2, 1, prices, dp);
            int skipSell = 0 + solve(i+1, 0, prices, dp);
            profit = max(sellElement, skipSell);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
