class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> map;

        int maxNumber = 0;
        for(int num : nums){
            map[num] = 1;
            maxNumber = max(maxNumber, num);
        }

        int minNumber = 1;
        for(auto p : map){
            if(p.first > minNumber || map.find(minNumber) == map.end()){
                return minNumber;
            }else{
                minNumber++;
            }
        }

        return maxNumber + 1;
    }
};
