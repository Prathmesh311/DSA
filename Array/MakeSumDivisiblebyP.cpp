class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> map;
        int currSum = 0;

        for(int num : nums){
            currSum = (currSum + num)% p;
        }
        int rem = currSum % p;

        if(rem == 0) return 0;

        currSum = 0;
        int minLen = nums.size();
        map[0] = -1;
        
        for(int i = 0; i < nums.size(); i++){
            currSum = (currSum + nums[i])% p;
            int prefix = (currSum - rem + p)% p;

            if(map.find(prefix) != map.end()){
                minLen = min(minLen, i - map[prefix]);
            }

            map[currSum] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};
