class Solution {
public:
    int dialer(vector<vector<int>> moves, vector<vector<int>> &dp, int pos, int remLen){
        if(remLen == 0){
            return 1;
        }

        if(dp[pos][remLen] != -1){
            return dp[pos][remLen];
        }

        int currPossibleNumbers = 0;
        for(int nextPos : moves[pos]){
            currPossibleNumbers = (currPossibleNumbers + dialer(moves, dp, nextPos, remLen-1)) % 1000000007;
        }

        return dp[pos][remLen] = currPossibleNumbers;
    }


    int knightDialer(int n) {
        vector<vector<int>> moves = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, {}, 
                                        {1,7,0}, {2,6}, {1,3}, {4,2}};
        vector<vector<int>> dp(10, vector<int>(n+1,0));

        //Iterative method
        for(int i=0;i<10;i++) {
            dp[i][1]=1;
        }

        if(n==1) return 10;
        for(int j=2;j<=n;j++) {
            for(int i=0;i<10;i++) {
                for(int pos : moves[i]) {
                    dp[i][j]=(dp[i][j]+dp[pos][j-1])%1000000007;
                }
            }
        }

        int ans=0;
        for(int i=0;i<10;i++) {
            ans=(ans+dp[i][n])%1000000007;
        }
        return ans;
         

        //Recursive method - but giving TLE error
        // int totalNumbers = 0;

        // for(int i=0; i <= 9; i++){
        //     totalNumbers = (totalNumbers + dialer(moves, dp, i, n-1)) % 1000000007;
        // }

        // return totalNumbers;        
    }
};
