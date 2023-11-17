class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size()-1;

        int maxSum = 0;
        while(start < end){
            maxSum = max(maxSum, nums[start] + nums[end]);
            start++;
            end--;
        }

        return maxSum;
    }
};
