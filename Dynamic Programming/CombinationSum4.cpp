class Solution {
public:
    int combinations(vector<int>& nums, vector<int>& dp, int target){
        if(target == 0){
            return 1;
        }

        if(target < 0){
            return 0;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        int currComb = 0;
        for(int i=0; i < nums.size(); i++){
            currComb += combinations(nums, dp, target - nums[i]);
        }

        return dp[target] = currComb;

    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return combinations(nums, dp, target);
    }
};
