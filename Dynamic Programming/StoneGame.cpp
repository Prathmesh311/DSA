class Solution {
public:
    bool game(vector<int>& piles, vector<bool>& dp, int start, int end, int currTotal){
        if(start > end){
            if(currTotal > 0){
                return true;
            }
            return false;
        }

        if(dp[end-start] != false){
            return dp[end-start];
        }



        bool firstEle = game(piles, dp, start + 1, end, currTotal + piles[start]);
        bool lastEle  = game(piles, dp, start, end - 1, currTotal - piles[end]);

        if(firstEle || lastEle){
            return dp[end-start] = true;
        }        

        return dp[end-start] = false;
    }

    bool stoneGame(vector<int>& piles) {
        vector<bool> dp(piles.size(), false);

        return game(piles, dp, 0, piles.size()-1, 0);
    }
};
