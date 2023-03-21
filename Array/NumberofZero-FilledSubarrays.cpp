class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long totalSubArrs = 0;

        for(int i=0 ; i <nums.size(); i++){
            if(nums[i] == 0){
                long long currSubArr = 0;
                long long continuesZero = 0;
                for(int j = i; j < nums.size(); j++){
                    if(nums[j] == 0){
                        continuesZero++;
                        i++;
                    }
                    else{
                        i = j;
                        break;
                    }
                }
                currSubArr = (continuesZero * (continuesZero+1))/2;
                totalSubArrs += currSubArr;
            }
        }
        
        return totalSubArrs;
    }
};
