class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> stack;
        
        stack.push({0, nums[0]});
        int currMin = nums[0];

        for(int i=1; i < nums.size(); i++){
            while(!stack.empty() && nums[stack.top().first] <= nums[i]){
                stack.pop();
            }

            if(!stack.empty() &&  stack.top().second < nums[i]){
                return true;
            }

            stack.push({i, currMin});
            currMin = min(currMin, nums[i]);
        }

        return false;
    }
};
