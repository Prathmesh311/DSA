class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;

        int deleted = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            deleted += nums[right] == 0;

            while(left < right && deleted > 1){
                deleted -= nums[left] == 0;
                left++;
            }

            maxLen = max(maxLen, right-left);
        }

        return maxLen;
    }
};
