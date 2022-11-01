class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101] = {0};
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        for(int i=2; i < nums.size(); i++){
           int maxProfit = 0;
           for(int j=i-2; j >= 0; j--){       //checking max profit in previous elements except last one
               maxProfit = max(dp[j], maxProfit);
           } 
            dp[i] = maxProfit + nums[i];
        }
        
        
        return max(dp[nums.size()-1], dp[nums.size()-2]);
    }
};
