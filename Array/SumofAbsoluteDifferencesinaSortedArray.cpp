class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for(int i=0; i < nums.size(); i++){
            int currDiff = (nums[i] * i - leftSum) + 
                            ((totalSum - leftSum - nums[i]) - (nums[i] * (nums.size() - i - 1)));

            ans.push_back(currDiff);
            leftSum += nums[i];
        }

        return ans;
    }
};
