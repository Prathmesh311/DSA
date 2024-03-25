class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        int index = 0;

         //swap numbers to their desired position
        while(index < nums.size()){
            if(nums[index] != nums[nums[index]-1]){
                swap(nums[index], nums[nums[index]-1]);
            }else{
                index++;
            }
        }

        //get numbers that are in wrong location
        for(int i=0; i < nums.size(); i++){
            if(nums[i] != i+1){
                duplicates.push_back(nums[i]);
            }
        }

        return duplicates;
    }
};
