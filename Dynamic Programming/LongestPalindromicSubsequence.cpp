class Solution {
public:
    int PalindromeSubseq(string s, vector<vector<int>> &dp, int start, int end){
        if(start > end){
            return 0;
        }
        if(start == end){
            return 1;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        if(s[start] == s[end]){
            dp[start][end] = PalindromeSubseq(s, dp, start + 1, end - 1) + 2;
        }
        else{
            dp[start][end] = max(PalindromeSubseq(s, dp, start+1, end),
                                 PalindromeSubseq(s, dp, start, end-1));
        }
        
        return dp[start][end];
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return PalindromeSubseq(s, dp, 0, s.size()-1);
    }
};
