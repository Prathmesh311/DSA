class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> map;

        for(int i=0; i < nums.size(); i++){
            if(map.find(target - nums[i]) != map.end()){
                ans.push_back(map[target-nums[i]]);
                ans.push_back(i+1);
                return ans;
            }
          
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = i+1;
            }
        }
        
        return ans;
    }
};
