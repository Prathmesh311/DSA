class Solution {
public:
    
     void findSubsets(vector<int>& nums, set<vector<int>>& ans, vector<int> subset, int i){
        //Base case
        if(i == nums.size()){
            sort(subset.begin(), subset.end());
            ans.insert(subset);
            return;
        }
        
        
        //Recursive case
        //Exclusing current element
        findSubsets(nums, ans, subset, i+1);
        
        //Including current element
        subset.push_back(nums[i]);
        findSubsets(nums, ans, subset, i+1);
        
        //Backtracking
        subset.pop_back();
        
        
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //vector<vector<int>> ret;
        set<vector<int>> ans;
        vector<int> subset;
        
        findSubsets(nums, ans, subset, 0);
        vector<vector<int>> ret(ans.begin(), ans.end());
      
        return ret;
    }
};
