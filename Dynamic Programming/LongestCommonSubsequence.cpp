class Solution {
public:
    
    int lcs(string text1, string text2, int dp[][1001], int n, int m){
        //Base case
        if(n == 0 || m == 0){
            return 0;
        }
        
        //Checking  if present in memory
        if(dp[n][m] != 0){
            return dp[n][m];
        }
        
        //Recursive case
        if(text1[n-1] == text2[m-1]){
            return dp[n][m] =  1 + lcs(text1, text2,dp, n-1, m-1);
        }
        else{
            int firstString = lcs(text1, text2,dp, n-1, m);
            int secondString =lcs(text1, text2,dp, n, m-1);
            return dp[n][m] =  max(firstString, secondString);
        }
        
    }
    
    int lcsTabulation(string text1, string text2){
         int dp[1001][1001];
        
        for(int i=0; i < text1.length()+1; i++){
            for(int j=0; j < text2.length()+1; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j]  = 0;
                }
                else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[text1.length()][text2.length()];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        //int dp[1001][1001] = {0};
        
        //return lcs(text1,text2,dp,text1.length(), text2.length());
        return lcsTabulation(text1, text2);
    }
};
