class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        map<int, int> count;
        int left = 0;
        int right = nums.size()-1;

        sort(nums.begin(), nums.end());

        for(int i=0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int target = 0 - nums[i];
            int left = i+1;
            int right = nums.size()-1;

            while(left < right){
                int currSum = nums[left] + nums[right];
                

                if(currSum == target){
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(currSum < target){
                    left++;
                }else{
                    right--;
                }
            }
        }

        return triplets;

    }
};