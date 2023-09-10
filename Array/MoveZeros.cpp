class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Two pointer technique
        int slow = 0;

        for(int fast=0; fast < nums.size(); fast++){
            if(nums[fast] != 0 && nums[slow] == 0){
                swap(nums[fast], nums[slow]);
            }
            if(nums[slow] != 0){
                slow++;
            }
        }

        //2nd technique:- bubble sort
        /*for(int i=0; i < nums.size(); i++){
            for(int j=0; j < nums.size() - i-1; j++){
                if(nums[j] == 0){
                    swap(nums[j], nums[j+1]);
                }
            }
        }*/
    }
};
