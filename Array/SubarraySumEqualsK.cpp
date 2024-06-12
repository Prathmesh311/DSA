class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixSum;

        prefixSum[0] = 1;

        int currSum = 0;
        int result = 0;

        for(int i=0; i < nums.size(); i++){
            currSum += nums[i];
             //check if some prefix are present in the array by removing them we can get a sum of k
            int possiblePrefix = currSum - k; 

            result += prefixSum[possiblePrefix];
            prefixSum[currSum] += 1;              //store/increment current prefix sum
        }

        return result;
    }
};
