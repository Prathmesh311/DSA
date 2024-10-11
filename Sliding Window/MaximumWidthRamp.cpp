class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> postFix(nums.size());
        int n = nums.size();
        int maxWidth = 0;

        postFix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            postFix[i] = max(postFix[i + 1], nums[i]);
        }
       
        int left = 0;
        for(int right = 1; right < postFix.size(); right++){
            while(nums[left] > postFix[right]){
                left++;
            }

            if (nums[left] <= postFix[right]) {
                maxWidth = max(maxWidth, right - left);
            }
        }

        return maxWidth;
    }
};
