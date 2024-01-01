class Solution {
public:
    void findSets(vector<int>& nums, vector<vector<int>> &sets, vector<int> &tempVec, int index, int target){
        if(target <= 0 || index >= nums.size()){
            if(target == 0){
                sets.push_back(tempVec);
            }
            return;
        }

        int prev = -1;

        for(int i = index; i < nums.size(); i++){
            if(nums[i] == prev){
                continue;
            }
            tempVec.push_back(nums[i]);
            findSets(nums, sets, tempVec, i+1, target-nums[i]);
            tempVec.pop_back();
            prev = nums[i];
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sets;
        vector<int> tempVec;

        sort(candidates.begin(), candidates.end());

        findSets(candidates, sets, tempVec, 0, target);
        
        return sets;
    }
};
