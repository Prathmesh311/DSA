class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        int steps = 0;

        while(left <= right){
            if(nums[left] == nums[right]){
                left++;
                right--;
            }else if(nums[left] > nums[right]){
                steps++;
                right--;
                nums[left] -= nums[right+1];
            }else if(nums[left] < nums[right]){
                steps++;
                left++;
                nums[right] -= nums[left-1];
            }
        }

        return steps;
    }
};
