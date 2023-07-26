class Solution {
public:
    int dfs(vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr == nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + dfs(nums, curr+1, curr, dp);
        }

        int exclude = dfs(nums, curr+1, prev, dp);

        return dp[curr][prev+1] = max(include, exclude);
    }


    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return dfs(nums, 0, -1, dp);
    }
};
