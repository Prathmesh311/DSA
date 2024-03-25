class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missingNumbers;
        int index = 0;

        //swap numbers to their desired position
        while(index < nums.size()){
            if(nums[index] != nums[nums[index]-1]){
                swap(nums[index], nums[nums[index]-1]);
            }else{
                index++;
            }
        }

        //get numbers that missing from location
        for(int i=0; i < nums.size(); i++){
            if(nums[i] != i+1){
                missingNumbers.push_back(i+1);
            }
        }

        return missingNumbers;
    }
};
