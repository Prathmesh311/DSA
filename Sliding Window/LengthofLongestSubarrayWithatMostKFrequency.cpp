class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int maxLen = 0;
        int left = 0;

        for(int right=0; right < nums.size(); right++){
            map[nums[right]] += 1;

            while(map[nums[right]] > k){
                map[nums[left]] -= 1;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
