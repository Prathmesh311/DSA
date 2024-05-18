class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stack;
        vector<int> nextGreater(nums.size(), -1);

        for(int iteration = 1; iteration <= 2; iteration++){    //Interate 2 times as given array is circular
            for(int i=0; i < nums.size(); i++){
                while(!stack.empty() && nums[stack.top()] < nums[i]){    //Monotonic Stack (decreasing)
                    int topIndex = stack.top();
                    stack.pop();

                    nextGreater[topIndex] = nums[i]; 
                }

                stack.push(i);
            }
        }

        return nextGreater;
    }
};
