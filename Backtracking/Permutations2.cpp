class Solution {
public:
    void findPermutations(vector<vector<int>>& result, vector<int>& nums, int index) {
        if (index >= nums.size()) {
            result.push_back(nums);  // Append a copy of nums
            return;
        }

        set<int> seen;  // Track seen elements to handle duplicates

        for (int i = index; i < nums.size(); ++i) {
            if (seen.find(nums[i]) != seen.end()) {
                continue;
            }

            seen.insert(nums[i]);
            
            swap(nums[index], nums[i]);
            findPermutations(result, nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;

        findPermutations(result, nums, 0);
        return result;
    }
};

