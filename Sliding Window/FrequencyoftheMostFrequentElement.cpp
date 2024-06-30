class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxFrequency = 1;

        sort(nums.begin(), nums.end());

        int left = 0;
        long sum = 0;


        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while (left < right && k < (long(nums[right]) * (right - left + 1) - sum)) {
                sum -= nums[left];
                left++;
            }

            maxFrequency = max(maxFrequency, right-left+1);
        }

        return maxFrequency;
    }
};
