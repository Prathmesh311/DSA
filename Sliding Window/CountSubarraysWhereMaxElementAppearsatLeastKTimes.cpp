class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = 0;
        int maxCount = 0;
        long long count = 0 ;
        int left = 0;

      
        maxEle = *max_element(nums.begin(), nums.end());

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == maxEle){
                maxCount += 1;
            }

            while(maxCount == k){
                if(nums[left] == maxEle){
                    maxCount -= 1;
                }
                left++;
            }
            
            count += left;
        }
        
        return count;
    }
};
