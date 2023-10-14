class Solution {
public:
    int paint(vector<int>& cost, vector<int>& time, vector<vector<int>> &dp, int i, int remain){
        if(remain <= 0){
            return 0;
        }
        if(i >= cost.size()){
            return 250000009;
        }

        if(dp[i][remain] != INT_MAX){
            return dp[i][remain];
        }

        int paintWall = cost[i] + paint(cost, time, dp, i+1, remain - 1 - time[i]);
        int skipWall = paint(cost, time, dp, i+1, remain);

        return dp[i][remain] = min(paintWall, skipWall);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size()+1, vector<int>(cost.size()+1, INT_MAX));

        return paint(cost, time, dp, 0, cost.size());
    }
};
