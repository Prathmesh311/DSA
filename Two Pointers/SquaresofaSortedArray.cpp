class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares(nums.size(), 0);

        int left = 0;
        int right = nums.size()-1;
        int index = nums.size()-1;

        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                squares[index--] = nums[left] * nums[left++];
            }else{
                squares[index--] = nums[right] * nums[right--];
            }
        }
        return squares;

    }
};
