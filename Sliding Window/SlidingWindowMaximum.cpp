class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;

        int start = 0;
        int end = 0;

        while(end-start < k){
            while(!q.empty() && q.back() < nums[end]){
                q.pop_back();
            }
            q.push_back(nums[end]);
            end++;
        }

        while(end < nums.size()){
            ans.push_back(q.front());

            if(nums[start] == q.front()){
                q.pop_front();
            }
            start++;

            while(!q.empty() && q.back() < nums[end]){
                q.pop_back();
            }

            q.push_back(nums[end]);
            end++;
        }

        ans.push_back(q.front());

        return ans;
    }
};
