class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while(right < nums.size()){
            while(right+1 < nums.size() && nums[right] == nums[right+1]){
                right++;
            }

            nums[left] = nums[right];
            left++;
            right++;
        }

        return left;
    }
};
