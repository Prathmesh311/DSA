class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size();
        int minOperations = INT_MAX;

        set<int> set(nums.begin(), nums.end());
        vector<int> uniqueNums(set.begin(), set.end());

        int right = 0;
        
        for(int left = 0; left < uniqueNums.size(); left++){

            while(right < uniqueNums.size() && uniqueNums[right] < uniqueNums[left] + len){
                right++;
            }

            minOperations = min(minOperations, len - (right-left));
        }

        return minOperations;
    }
};
