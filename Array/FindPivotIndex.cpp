class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0; i < nums.size(); i++){
           totalSum += nums[i];
        }

        int left = 0;
        int right = 0;

        for(int i=0; i < nums.size(); i++){
            if(i != 0){
                left += nums[i-1];
            }
            
            right = totalSum - left - nums[i];

            if(left == right){
                return i;
            }
        }

        return -1;
    }
};