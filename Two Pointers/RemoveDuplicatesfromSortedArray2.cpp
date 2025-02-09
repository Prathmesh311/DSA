class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int left = 0;

        for(int i = 0; i < nums.size(); i++){
            while(i+1 < nums.size() && nums[i] == nums[i+1]){
                count++;
                i++;
            }

            if(count >= 2){
                nums[left] = nums[i];
                left++;
            }

            nums[left] = nums[i];
            left++;
            count = 1;
        }

        return left;
    }
};
