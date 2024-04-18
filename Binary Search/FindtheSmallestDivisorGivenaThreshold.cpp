class Solution {
public:
    bool isFeasible(vector<int>& nums, int threshold, int divisor){
        int currentSum = 0;

        for(int num : nums){
            currentSum += num / divisor;
            currentSum += num % divisor ? 1 : 0;

            if(currentSum > threshold){
                return false;
            }
        }

        return true;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while(left < right){
            int mid = left + (right-left)/2;

            if(isFeasible(nums, threshold, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};
