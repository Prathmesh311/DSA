class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxValue = 0;
        
        for(int i=0; i < candies.size(); i++){
            maxValue = max(maxValue,candies[i]);
        }

        for(int i=0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maxValue){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
           
        }
        return ans;

    }
};
