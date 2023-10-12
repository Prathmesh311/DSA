class Solution {
public:
//MaxSubArrSum = max(maxSubarr in normal array ans, total sum - minSubAr) which is part of circular array 
    int maxSubarraySumCircular(vector<int>& nums) {  
        int maxSum = 0;
        int globalMax = INT_MIN;
        int minSum = 0;
        int globalMin = INT_MAX;
        int totalSum = 0;

        for(int i=0; i < nums.size(); i++){
            maxSum += nums[i];
            minSum += nums[i];
            totalSum += nums[i];

            globalMax = max(globalMax, maxSum);
            globalMin = min(globalMin, minSum);

            if(maxSum < 0){
                maxSum = 0;
            }
            if(minSum > 0){
                minSum = 0;
            }
        }

        if(globalMax < 0){
            return globalMax;
        }
        
        return max(globalMax, totalSum - globalMin);  
    }
};
