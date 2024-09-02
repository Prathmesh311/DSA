class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minVal = nums[n-1];
        int maxVal = nums[0];

        int start = 0;
        int end = 0;


        for(int i=0; i < n; i++){
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[n-1-i]);

            if(nums[i] < maxVal){
                end = i;
            } 
            if(nums[n-1-i] > minVal){
                start = n - 1 - i;
            }
        }

        return end > start ? end - start + 1 : 0;
    }
};
