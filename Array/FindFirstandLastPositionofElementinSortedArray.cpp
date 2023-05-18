class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = -1;
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                pos = mid;
                break;
            }
            else if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        vector<int> ans;

        if(pos == -1){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            int start = pos;
            int end = pos;

            while(start >= 0 && nums[start] == target){
                start--;
            }

            while(end < nums.size() && nums[end] == target){
                end++;
            }

            ans.push_back(start+1);
            ans.push_back(end-1);
        }
        return ans;
    }
};
