class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLen = 0;
        int currLen = 0;
        
        for(int i=0; i < nums.size(); i++){
            int startIndex = i;
            currLen = 0;
            if(nums[i] % 2 == 0 && nums[i] <= threshold){
                
                currLen = 1;
                 while(i < nums.size() && nums[i] <= threshold){
                
                     if(i+1 < nums.size() && nums[i] % 2 != nums[i + 1] % 2 &&  nums[i+1] <= threshold){
                         currLen++;
                         i++;
                     }
                     else{
                         break;
                     }
                 }
                
                 maxLen = max(maxLen, currLen);
            }
        }
        
        
        return maxLen;
        
    }
};
