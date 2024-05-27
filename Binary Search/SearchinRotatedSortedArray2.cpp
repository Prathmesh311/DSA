class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = (left + right)/2;

            if(nums[mid] == target){
                return true;
            }

            //As left & mid elements are equal. It was difficult to find which part of array is sorted. Hence shrink the array
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
                continue;
            }

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target <= nums[mid]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                if(nums[mid] <= target && target <= nums[right]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }

        }

        return false;
    }
};
