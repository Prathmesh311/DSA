class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for(int num : nums){
            if(num <= firstMin){
                firstMin = num;
            }else if(num <= secondMin){
                secondMin = num;
            }else{
                return true;
            }
        }

        return false;
    }
};
