class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxNum = nums[0];
        int minNum = nums[0];

        for(int i=1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(maxNum, minNum);
            }

            maxNum = max(nums[i], maxNum * nums[i]);
            minNum = min(nums[i], minNum * nums[i]);
            ans = max(maxNum, ans);
        }

        return ans;
        
    }
};
