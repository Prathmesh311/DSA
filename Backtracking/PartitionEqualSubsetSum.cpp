class Solution {
public:
    
    bool subset(vector<int>& nums, int target, int i){
        //Base case
        if(target == 0){
            return true;
        }
        
        if(i >= nums.size() || target < 0){
            return false;
        }
        
        
        //Recursive case
        bool including = subset(nums, target - nums[i], i+1);
        bool excluding =  subset(nums, target, i+1);
        
        if(including || excluding){
            return true;
        }
        return false;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int i=0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
         
        return subset(nums, sum/2, 0);
    }
};
