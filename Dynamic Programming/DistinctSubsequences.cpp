class Solution {
public:
    int dfs(string &s, string &t, vector<vector<int>> &dp, int i, int j){
        if(j >= t.size()){
            return 1;
        }
        if(i >= s.size() && j < t.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            dp[i][j] = dfs(s, t, dp, i+1, j+1) + dfs(s, t, dp, i+1, j);
        }else{
            dp[i][j] = dfs(s, t, dp, i+1, j);
        }

        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        
        return dfs(s, t, dp, 0, 0);
    }
};
