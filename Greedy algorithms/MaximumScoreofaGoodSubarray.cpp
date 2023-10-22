class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int left = k;
        int right = k;
        int n = nums.size();

        int minValue = nums[k];
        int maxScore = nums[k];

        int leftVal = 0;
        int rightVal = 0;

        while(left > 0 || right < n){
            if(left != 0){
                leftVal = nums[left-1];
            }
            if(right != n-1){
                rightVal = nums[right+1];
            }

            if(leftVal > rightVal){
                left--;
                minValue = min(minValue, leftVal);
            }else{
                right++;
                minValue = min(minValue, rightVal);
            }
            
            maxScore = max(maxScore, minValue * (right-left+1));
            rightVal = 0;
            leftVal = 0;
        }


        return maxScore;
    }
};
