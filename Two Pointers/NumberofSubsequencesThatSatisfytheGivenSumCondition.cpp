class Solution {
public:
    int mod = 1000000007;
    long long mod_pow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
                exp--;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    int numSubseq(vector<int>& nums, int target) {
        int numberOfSubsequences = 0;

        int left = 0;
        int right = nums.size()-1;

        sort(nums.begin(), nums.end());

        while(left <= right){
            int currSum = nums[left] + nums[right];

            if(currSum > target){
                right--;
            }else{
                long long currSubsequences = (long long)mod_pow(2, right-left) % mod;
                numberOfSubsequences = (numberOfSubsequences + currSubsequences) % mod;
                left++;
            }
        }

        return numberOfSubsequences;
    }
};
