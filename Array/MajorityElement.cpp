class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int mejority;
        int maxAppearance = 0;

        for(int i=0; i < nums.size(); i++) {
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 1;
                if(maxAppearance < map[nums[i]]){
                    maxAppearance = map[nums[i]];
                    mejority = nums[i];
                }
            }
            else{
                map[nums[i]] += 1;

                if(maxAppearance < map[nums[i]]){
                    maxAppearance = map[nums[i]];
                    mejority = nums[i];
                }
            }
        }

        return mejority;
        
    }
};
