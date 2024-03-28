class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;

        int product = 1;
        int subArrays = 0;

        for(int right = 0; right < nums.size(); right++){
            product = product * nums[right];

            //reduce product by removing left element from subarray
            while(product >= k && left <= right){
                product = product / nums[left];
                left++; 
            }

            //For every addition of position/number in subarray
            //every number addition to subarray result in addition of following numbers.
            subArrays += (right - left + 1);
        }

        return subArrays;
    }
};
