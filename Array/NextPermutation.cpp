class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos1 = -1;
        int pos2;

        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pos1 = i;
                break;
            }
        }

        if(pos1 == -1){
            reverse(nums.begin(), nums.end());
        }else{
            for(int i=nums.size()-1; i >= pos1; i--){
                if(nums[i] > nums[pos1]){
                    pos2 = i;
                    break;
                }
            }
            swap(nums[pos1], nums[pos2]);
            reverse(nums.begin() + pos1+1, nums.end());
        }
        
    }
};
