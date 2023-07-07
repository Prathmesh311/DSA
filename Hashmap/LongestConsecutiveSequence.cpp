class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> map;

        if(nums.size() == 0){
            return 0;
        }

        for(int num : nums){             //creating ordererd hashmap
            map[num] += 1;
        }


        int preNum = -1000000001;
        int consecutiveLen = 0;
        int maxConsecutiveLen = 0;
        
        for(auto p : map){
            int value = p.first;

            if(abs(value-preNum) == 1){ //if element is consecutive add to count
                consecutiveLen++;
                maxConsecutiveLen = max(maxConsecutiveLen, consecutiveLen);
            }
            else{
                consecutiveLen = 0;
            }

            preNum = value;            //set previous number
        }

        return maxConsecutiveLen+1;
    }
};
