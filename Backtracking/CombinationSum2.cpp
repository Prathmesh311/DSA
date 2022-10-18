class Solution {
public:
    int t;
     void combinations(vector<int>& candidates, set<vector<int>>& ans, vector<int>& comb, int target, int i, int n){
        //Base case
        if(target == 0){
            int val=0;
            for(int i=0; i < comb.size(); i++){
                val += comb[i];
            }
            if(val == t){
                std::sort(comb.begin(),comb.end());
                ans.insert(comb);
            }
            return;
        }
        if( i >= n || target < 0){
            
            return;
        }
        
        
        //Recursive case
        if(target >= candidates[i]){
            comb.push_back(candidates[i]);
            combinations(candidates, ans,comb, target - candidates[i], i+1, n);
            comb.pop_back();
           
        }
        
            combinations(candidates, ans, comb, target, i+1, n);
       
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> comb;
        t = target;
        combinations(candidates, ans, comb, target, 0, candidates.size());
        std::vector<vector<int>> v(ans.begin(), ans.end());
       
        return v;
    }
};
