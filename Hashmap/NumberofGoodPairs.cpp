class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> map;

        for(int i=0; i < nums.size(); i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 1;
            }else{
                map[nums[i]] += 1;
            }
        }

        int totalGoodPairs = 0;
        for(auto pair: map){
            int numCount = pair.second;

            if(numCount > 1){
                totalGoodPairs += (numCount * (numCount - 1)) / 2;
            }
        }

        return totalGoodPairs;
    }
};
