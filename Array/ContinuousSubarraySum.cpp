class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> prefixSum(nums.size()+1, 0);
        map[0] = -1;
       

        for(int i = 0; i < nums.size(); i++){
            prefixSum[i+1] = nums[i] + prefixSum[i];

            int rem = prefixSum[i+1] % k;

            if(map.find(rem) != map.end()){
                if(i - map[rem] >= 2){
                    return true;
                }
            }else{
                map[rem] = i;
            }
        }

        return false;
    }
};
