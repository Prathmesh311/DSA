class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> subArrayMap;
        subArrayMap[0] = 1;

        int possibleSums = 0;
        int sum = 0;

        for(int i=0; i < nums.size(); i++){
            sum += nums[i];
            int rem = ((sum % k) + k)%k;
           
            if(subArrayMap.find(rem) != subArrayMap.end()){
                possibleSums += subArrayMap[rem];                
            }

            subArrayMap[rem] += 1;
        }

        return possibleSums;
    }
};
