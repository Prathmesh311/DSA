class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum += num;
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int high = prefixSum[right];
        int low = left - 1 >= 0 ? prefixSum[left-1] : 0;

        return high - low;
    }
};
