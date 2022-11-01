class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[10001] = {1001};
        std::fill_n(dp, 10001, 10001);
      
        //If 1st element is 0 then no path present
        if(nums[0] == 0){
            return 0;
        }
       
        dp[0] = 0;
        
        for(int i=0; i < nums.size(); i++){
            if(dp[i] != 10001){             //Check if this element reached by previous elements
                for(int j = i+1; j <= i + nums[i] && j < nums.size(); j++){
                    dp[j] = min(dp[j], dp[i]+1);
                }
            }
        }
        
        
        return dp[nums.size()-1];
        
    }
};
