class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> map;
        int tuples = 0;

        for(int i=0; i < nums.size(); i++){
            for(int j=i+1; j < nums.size(); j++){
                int product = nums[i] * nums[j];
                map[product] += 1;
            }
        }

        for(auto p : map){
            int count = p.second;

            int combinations = count * (count-1) / 2;
            tuples += 8 * combinations;
        }

        return tuples;
    }
};
