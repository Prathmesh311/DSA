class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;

        int left = 0;
        int flips = 0;

        for(int right = 0; right < nums.size(); right++){
            flips += nums[right] == 0;

            while(left <= right && flips > k){
                flips -= nums[left] == 0;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
