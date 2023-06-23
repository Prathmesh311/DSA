class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;

        for(int i=0; i < nums.size(); i++){
            
                map[nums[i]].push_back(i);
            
        }

        for(auto p : map){
            int num = p.first;
            vector<int> numPos = p.second;

            for(int i=1; i < numPos.size(); i++){
                if(numPos[i] - numPos[i-1] <= k){
                    return true;
                }
            }
        }

        return false;
    }
};
