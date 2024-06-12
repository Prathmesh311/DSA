class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroEnd = 0;
        int oneEnd = 0;

        int index = 0;

        while(index < nums.size()){
            if(nums[index] == 0){
                swap(nums[index], nums[zeroEnd]);
                zeroEnd++;
            }
            else if(nums[index] == 1){
                if(zeroEnd >= oneEnd){
                    oneEnd = zeroEnd;
                }
                swap(nums[index], nums[oneEnd]);
                oneEnd++;
            }

            index++;
        }

        //2nd iteration
        index = 0;
        zeroEnd = 0;
        oneEnd = 0;

         while(index < nums.size()){
            if(nums[index] == 0){
                swap(nums[index], nums[zeroEnd]);
                zeroEnd++;
            }
            else if(nums[index] == 1){
                if(zeroEnd >= oneEnd){
                    oneEnd = zeroEnd;
                }
                swap(nums[index], nums[oneEnd]);
                oneEnd++;
            }

            index++;
        }

    }
};
