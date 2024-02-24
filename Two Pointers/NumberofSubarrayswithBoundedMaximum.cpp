class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        int totalSubArrays = 0;
        int start = -1;
        int currSubArrays = 0;

        for(int i=0; i < nums.size(); i++){
            if(nums[i] > right){               //If curr element is larger that limit start new subarray 
                start = i;
                currSubArrays = 0;
            }

            if(left <= nums[i] && nums[i] <= right){      //if element within limit find new subarrays that can be added in existing subarrays
                currSubArrays = i - start;
            }

            totalSubArrays += currSubArrays;      //add to total
        }

        return totalSubArrays;
        
    }
};
