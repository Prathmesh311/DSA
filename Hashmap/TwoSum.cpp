class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;
        vector<int> ans;

        for(int i=0; i < nums.size(); i++){
            if(map.find(target - nums[i]) != map.end()){
                
                ans.push_back(map[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            
            if(map.find(nums[i]) == map.end()){
                map.insert(make_pair(nums[i], i));
            }
            
        }
        return ans;
    }
};
