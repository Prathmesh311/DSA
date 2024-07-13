class Solution {
public:
    void findQuadtruples(vector<int> &nums, vector<vector<int>> &quadtruples, int prevLeft, int prevRight, int left, int right, long long target){
        while(left < right){
            long long currSum = static_cast<long long>(nums[left]) + nums[right];

            if(currSum == target){
                quadtruples.push_back({prevLeft, nums[left], nums[right], prevRight});
                
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right]== nums[right-1]) right--;

                left++;
                right--;

            }else if(currSum > target){
                right--;
            }else{
                left++;
            }
        }
    }


    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadtruples;

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;

        for(int i=0; i < nums.size(); i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j=i+1; j < nums.size(); j++){
                if(j > i+1 && nums[j-1] == nums[j]) continue;

                long long newTarget =  static_cast<long long>(target) - nums[i] - nums[j];
                findQuadtruples(nums, quadtruples, nums[i], nums[j], j+1, nums.size()-1, newTarget);
            }
        }

        return quadtruples;
    }
};
