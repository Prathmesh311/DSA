class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        int left = 0;
        int right = 0;

        for(; right < nums.size(); right++){
            while(!dq.empty() && nums[right] > dq.back()){
                dq.pop_back();
            }

            dq.push_back(nums[right]);

            while(right - left >= k){
                if(dq.front() == nums[left]){
                    dq.pop_front();
                }
                left++;
            }

            if(right-left == k-1){
                result.push_back(dq.front());
            }
        }

        return result;
    }
};
