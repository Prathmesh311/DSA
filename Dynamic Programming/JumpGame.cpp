class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int end = nums.size()-1;

        bool dp[10001] = {false};
        dp[0] = true;
        
        if(nums.size() == 1){
            return true;
        }
       
        while(i <= end){
           
            if(dp[i]){
                for(int j=0; j <= nums[i] && i+j <= end; j++){
                    dp[i+j] = true;
                    if(i+j == end){
                        return true;
                    }
                }
            }
            i++; 
        }
        
        return dp[end];
    }
};
