class Solution {
public:
    bool canSplite(vector<int>& nums, int mid, int k){
        int currSum = 0;
        for(int num : nums){
            currSum += num;
            if(currSum > mid){
                currSum = num;
                k--;
            }
        }

        return k < 1;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while(left < right){
            int mid = left + (right - left)/2;

            if(!canSplite(nums, mid, k)){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        return left;
    }
};
