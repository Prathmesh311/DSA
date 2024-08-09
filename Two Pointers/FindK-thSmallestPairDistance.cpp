class Solution {
public:
    //Using shrincable sliding window find all possible diff less than k
    int pairsLessThanDistance(vector<int>& nums, int k){
        int totalPairs = 0;

        int left = 0;
        int right = 1;

        while(right < nums.size()){
            while(nums[right] - nums[left] > k){
                left++;
            }

            totalPairs += right-left;
            right++;
        }

        return totalPairs;
    }

    //Binary search on possible differences and find kth diff
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums[nums.size()-1] - nums[0];

        while(start < end){
            int mid = start + (end - start)/ 2;

            int currPairs = pairsLessThanDistance(nums, mid);

            if(currPairs < k){
                start = mid+1;
            }else{
                end = mid;
            }
        }

        return start;
    }
};
