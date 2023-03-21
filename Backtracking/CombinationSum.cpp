class Solution {
public:
    void combinations(vector<vector<int>>& ans, vector<int>& comb, vector<int>& candidates, int i, int target){
        if(target <= 0 || candidates.size() <= i){
            if(target == 0){
                ans.push_back(comb);
            }
            return;
        }

        
        if(target >= candidates[i]){
            comb.push_back(candidates[i]);
            combinations(ans, comb, candidates, i, target - candidates[i]);
            comb.pop_back();
        }
        

        combinations(ans, comb, candidates, i+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        combinations(ans, comb, candidates, 0, target);
        return ans;
    }
};
