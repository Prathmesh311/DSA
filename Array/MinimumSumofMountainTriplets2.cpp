class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> minLeft(nums.size(), INT_MAX);
        vector<int> minRight(nums.size(), INT_MAX);

        int currMin = nums[0];
        for(int i=1; i < nums.size(); i++){
            currMin = min(currMin, nums[i-1]);
            minLeft[i] = currMin;
        }

        currMin = nums[nums.size()-1];
        for(int i=nums.size()-2; i >= 0; i--){
            currMin = min(currMin, nums[i+1]);
            minRight[i] = currMin;
        }

        int minSum = INT_MAX;
        for(int i=1; i < nums.size()-1; i++){
            if(minLeft[i] < nums[i] && nums[i] > minRight[i]){
                int currSum = minLeft[i] + nums[i] + minRight[i];
                minSum = min(minSum, currSum);
            }
        }

        if(minSum == INT_MAX){
            return -1;
        }
        return minSum;
    }
};
