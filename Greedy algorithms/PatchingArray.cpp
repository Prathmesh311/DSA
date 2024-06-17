class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long value = 1;
        int i = 0;

        while(value <= n){
            if(i < nums.size() && nums[i] <= value){
                value += nums[i];
                i++;
            }else{
                patches++;
                value += value;
            }
        }

        return patches;
    }
};
