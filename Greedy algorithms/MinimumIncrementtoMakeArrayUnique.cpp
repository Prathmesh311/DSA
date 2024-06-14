class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, bool> map;
        int totalIncreaments = 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i < nums.size(); i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = true;
            }else{
                int currAdd = (nums[i-1] - nums[i]) + 1;
            
                map[nums[i] + currAdd] = true;
                nums[i] += currAdd;
               
                totalIncreaments += currAdd;
            }
        }

        return totalIncreaments;
    }
};
