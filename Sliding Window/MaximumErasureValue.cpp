class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> map;

        int maxSum = 0;
        int currSum = 0;
        int left = 0;


        for(int right = 0; right < nums.size(); right++){
            map[nums[right]] += 1;
            currSum += nums[right];

            while(map[nums[right]] > 1){
                map[nums[left]] -= 1;
                currSum -= nums[left];
                left++;
            }

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
