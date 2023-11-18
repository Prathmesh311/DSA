class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        map<int, int> map;

        for(int i=0; i < nums.size(); i++){
            map[nums[i]] += 1;
        }

        for(int i=0; i < nums.size(); i++){
            if(map[nums[i]] == 1 && 
                map.find(nums[i]-1) == map.end() && 
                map.find(nums[i]+1) == map.end()){ 
                ans.push_back(nums[i]); 
            }
        }

        return ans;
    }
};
