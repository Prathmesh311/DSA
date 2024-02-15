class Solution {
public:
    //Method 1: Recursion Memoization -> TLE
    bool equalSubset(vector<int>& nums, vector<vector<bool>> &dp, int index, int target){
        if(index < 0){
            return false;
        }
        if(target == 0){
            return dp[index][target] = true;
        }
        
        if(target < 0){
            return  false;
        }

        if(dp[index][target]){
            return dp[index][target];
        }


        bool include = equalSubset(nums, dp, index-1, target-nums[index]);
        bool exclude = equalSubset(nums, dp, index-1, target);

        if(include || exclude){
            return dp[index][target] = true;
        }

        return dp[index][target] = false; 
    }

    
    bool equalSubsetTabular(vector<int>& nums, vector<vector<bool>> &dp, int t){
        for(int i=0; i < nums.size(); i++){
            for(int target = 0; target <= t; target++){
                if(i == 0 && target == 0){
                    dp[i][target] = true;
                }
                else if(i == 0){
                    dp[i][target] = false;
                }
                else if(target == 0){
                    dp[i][target] = true;
                }
                else if(target >= nums[i-1]){
                    dp[i][target] = dp[i-1][target - nums[i-1]] || dp[i-1][target];
                }
                else if(dp[i-1][target]){
                    dp[i][target] = true;
                }
                else{
                    dp[i][target] = false;
                }
            }
        }

        return dp[nums.size()-1][t];

    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        if(sum % 2 != 0){
            return false;
        }

        int target = sum/2;

        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1, false));

        return equalSubsetTabular(nums, dp, target);

        return equalSubset(nums, dp, nums.size()-1, target);
    }
};
