class Solution {
public:
    
    int targetSum(vector<int>& nums, map<pair<int, int>, int>& dp, int sum, int i, int target){
        //Base case
        if(i >= nums.size()){
            if(sum == target){
                return 1;
            }
            return 0;
        }
        
        if (dp.find({sum, i}) != dp.end()){
            return dp[{sum, i}];
        }
        
        //Recursive case
        int adding = targetSum(nums, dp, sum + nums[i], i+1, target);
        int subtracting = targetSum(nums, dp, sum - nums[i], i+1, target);
        
        return dp[{sum, i}] = adding+subtracting;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        map<pair<int, int>, int> dp;
        
        return targetSum(nums, dp, 0, 0, target);
    }
};
