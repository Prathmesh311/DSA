class Solution {
public:
    int match(vector<vector<int>> &dp, string &s, string &p, int i, int j){
        
        if(i >= s.size() || j >= p.size()){
            if(i >= s.size() && j >= p.size()){
                return 1;
            }else if(i >= s.size()){
                while(j < p.size() && p[j] == '*'){
                    j++;
                }

                if(j >= p.size()){
                    return 1;
                }
            }
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(p[j] == '*'){
            dp[i][j] = match(dp, s, p, i, j+1) || match(dp, s, p, i+1, j);
        }else if(p[j] == '?' || s[i] == p[j]){
            dp[i][j] = match(dp, s, p, i+1, j+1);
        }else{
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    bool isMatch(string s, string p) {

       vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));

       return match(dp, s, p, 0, 0) >= 1;
    }
};
