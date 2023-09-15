class Solution {
public:
    void findPermutations(vector<int>& nums, vector<vector<int>> &ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = index; j < nums.size(); j++){
            swap(nums[index], nums[j]);
            findPermutations(nums, ans, index+1);
            swap(nums[index], nums[j]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        findPermutations(nums, ans, 0);
        return ans;
    }
};
