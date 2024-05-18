class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int, int> map;

        for(int i=0; i < nums2.size(); i++){
            while(!stack.empty() && nums2[stack.top()] < nums2[i]){
                int topIndex = stack.top();
                stack.pop();

                map[nums2[topIndex]] = nums2[i];
            }

            stack.push(i);
        }

        vector<int> ans;
        for(int num : nums1){
            int nextGreater = map[num] != 0 ? map[num] : -1;
            ans.push_back(nextGreater);
        }

        return ans;
    }
};
