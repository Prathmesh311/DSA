class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int first = 0;
        int second = 0;
        int currSum = 0;
        int minLen = INT_MAX;

        while(first < nums.size()){
           int check = 0;
           int prevSecond = second;

            while(first <= second && second < nums.size()){
                if(prevSecond < second || second == 0){     //Add to sum if new second pointer position found
                    currSum += nums[second];  
                }

                if(currSum < target){                       //increment second pointer untill sum is less than target 
                    prevSecond = second;
                    second++;
                }
                else if(currSum >= target){                 //sum == target count minLen, increment first pointer
                    minLen = min(minLen, (second-first)+1);
                    currSum -= nums[first];
                    first++;
                    check = 1;
                    prevSecond = second;
                }
            }
            if(check == 0){
                currSum -= nums[first];
                first++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
