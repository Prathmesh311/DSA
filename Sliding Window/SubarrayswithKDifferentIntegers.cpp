class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        int leftNear = 0;
        int leftFar = 0;
        int ans = 0;


        for(int r = 0; r < nums.size(); r++){
            count[nums[r]] += 1;

            //if extra element present
            while(count.size() > k){
                count[nums[leftNear]] -= 1;
                if(count[nums[leftNear]] == 0){
                    count.erase(nums[leftNear]);
                }
                leftNear++;
                leftFar = leftNear;
            }

            //if 
            while(count[nums[leftNear]] > 1){
                count[nums[leftNear]] -= 1;
                leftNear++;
            }

            if(count.size() == k){
                ans += leftNear - leftFar + 1;
            }
        }

        return ans;
    }
};
