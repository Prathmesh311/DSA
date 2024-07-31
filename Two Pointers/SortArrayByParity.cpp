class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even = 0;
        int index = 0;

        while(index < nums.size()){
            if(nums[index] % 2 == 0){
                swap(nums[index], nums[even]);
                even++;
                if(even > index){
                    index = even;
                }
            }else{
                index++;
            }
        }

        return nums;
    }
};
