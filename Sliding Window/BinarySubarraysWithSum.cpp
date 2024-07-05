class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }

        int subArrays = 0;

        int left = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right++){
            count += nums[right];

            while(left <= right && count > goal){
                count -= nums[left];
                left++;
            }   
            
            subArrays += right - left + 1;
        }

        return subArrays;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};
