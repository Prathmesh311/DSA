class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        long dp[n+2];
        
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){

          dp[i]=(dp[i-1]+(i-1)*dp[i-2])%1000000007;

       }

       return (int)dp[n];
        
    }
};    
