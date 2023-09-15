class Solution {
public:
    bool partition(vector<int> &nums, vector<int> &used, int subsetSum, int target, int k, int index){
        if(k == 0){
            return true;
        }

        if(subsetSum == target){                              // If 1 partition found recursively find next partitions
            return partition(nums, used, 0, target, k-1, 0);
        }

        for(int j = index; j < nums.size(); j++){
            if(used[j] == 0 && subsetSum + nums[j] <= target){   // include in partition if not previously used and within that target limit
                used[j] = 1;

                if(partition(nums, used, subsetSum + nums[j], target, k, j+1)){
                    return true;
                }

                used[j] = 0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> used(nums.size(), 0);
        int subsetSum = 0;
        int target = 0;

        for(int value : nums){
            target += value;
        }
        
        if(target%k != 0){               // checking if partition is posible in k parts
            return false;
        }

        target = target / k;

        return partition(nums, used, subsetSum, target, k, 0);
    }
};
