class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;

        int two = nums.size()-1;
        int index = 0;

        while(index <= two){
            if(nums[index] == 0){
                swap(nums[index], nums[zero]);
                zero++;
                if(zero > one){
                    one == zero;
                }
                index++;
            }else if(nums[index] == 1){
                one++;
                index++;
            }else{
                swap(nums[index], nums[two]);
                two--;
            }
        }
    }
};
