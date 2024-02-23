#include <vector>
#include <map> // Include map header
#include <algorithm>

using namespace std;

class Solution {
public:
    int burstBallons(vector<int>& nums, vector<vector<int>> &dp, int left, int right){
        if(left > right){
            return 0;
        }

        if(dp[left][right] != 0){
            return dp[left][right];
        }

        // find the last burst in nums[left]...nums[right]
        int result = 0;
        for (int i = left; i <= right; i++) {
            // nums[i] is the last burst
            int curr = nums[left - 1] * nums[i] * nums[right + 1];
            // nums[i] is fixed, recursively call left & right sides
            int remaining = burstBallons(nums, dp, left, i - 1) + burstBallons(nums, dp, i + 1, right);
            result = max(result, curr + remaining);
        }

        // add to cache
        return dp[left][right] = result;
    }

    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return burstBallons(nums, dp, 1, nums.size()-2);
    }
};
