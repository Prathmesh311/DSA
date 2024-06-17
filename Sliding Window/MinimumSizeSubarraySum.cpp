class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int start = 0;

        int minSize = INT_MAX;

        for(int end=0; end < nums.size(); end++){
            sum += nums[end];
            while(sum >= target){
                minSize = min(minSize, end-start);
                sum -= nums[start++];
            }
        }

        return minSize == INT_MAX ? 0 : minSize + 1;
    }
};
