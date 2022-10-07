class Solution {
public:
    
    void findSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int> subset, int i){
        //Base case
        if(i == nums.size()){
            ans.push_back(subset);
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
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        
        findSubsets(nums, ans, subset, 0);
        
        return ans;
    }
};
