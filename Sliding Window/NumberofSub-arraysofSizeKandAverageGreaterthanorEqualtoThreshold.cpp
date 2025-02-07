class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;

        int left = 0;
        int currSum = 0;

        for(int right=0; right < arr.size(); right++){
            currSum += arr[right];

            if(right - left + 1 > k){
                currSum -= arr[left];
                left++;
            }

            if(right - left + 1 < k){
                continue;
            }
            
            int currAvg = currSum / (right-left+1);

            if(currAvg >= threshold){
                count++;
            }
        }
        
        return count;
    }
};
