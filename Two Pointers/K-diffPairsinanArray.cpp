class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int totalPairs = 0;

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 1;

        while(right < nums.size()){
            if(abs(nums[right] - nums[left]) == k){
                totalPairs++;
                right++;
                left++;

                while(right < nums.size() && nums[right-1] == nums[right]) right++;
                    right++;
                }

                while(left+1 < right && nums[left-1] == nums[left]){
                    left++;
                }
            }else if(abs(nums[right] - nums[left]) < k){
                right++;
            }else{
                if(left+1 < right){
                    left++;
                }else{
                    right++;
                    left++;
                }
            }
        }

        return totalPairs;
    }
};
