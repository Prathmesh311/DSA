class Solution {
public:
    int atMost(vector<int> &nums, int k){
        int oddCount = 0;
        int subArrays = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] % 2 == 1){
                oddCount++;
            }

            while(left <= right && oddCount > k){
                if(nums[left] % 2 == 1){
                    oddCount--;
                }
                left++;
            }

            subArrays += right - left + 1;
        }

        return subArrays;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
