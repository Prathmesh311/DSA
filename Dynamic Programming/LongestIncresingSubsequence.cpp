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

     int solveLIS(vector<int>& nums){
        vector<int> ans;
        int n = nums.size();

        if(n == 0){
            return 0;
        }

        ans.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
           
        }

        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {

        return solveLIS(nums);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return dfs(nums, 0, -1, dp);
    }
};
