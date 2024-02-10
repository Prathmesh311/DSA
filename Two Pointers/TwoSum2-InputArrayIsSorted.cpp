class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        vector<int> ans;

        while(left <= right){
            int currSum = numbers[left] + numbers[right];

            if(currSum == target){
                ans = {left+1, right+1};
                return ans;
            }
            if(currSum < target){
                left++;
            }
            else{
                right--;
            }
        }

        return ans;
    }
};
