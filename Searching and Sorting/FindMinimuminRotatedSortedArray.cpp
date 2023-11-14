class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        int minValue = INT_MAX;
        while(start <= end){
            if(nums[start] < nums[end]){
                minValue = min(minValue, nums[start]);
                break;
            }

            int mid = (start + end)/2;
            minValue = min(minValue, nums[mid]);

            if(nums[start] <= nums[mid]){
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }

        return minValue;
    }
};
