class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp = {{}, {1,1,1,1,1}};
        
        int a=0, e=1, i=2, o=3, u=4;
        int mod = 1000000007;

        for(int index=2; index <= n; index++){   //according to conditions find prev possible char and add them up and store in dp
            dp.push_back({0,0,0,0,0});

            dp[index][a] = (dp[index-1][e] + dp[index-1][i] + dp[index-1][u]) % mod;
            dp[index][e] = (dp[index-1][a] + dp[index-1][i]) % mod;
            dp[index][i] = (dp[index-1][o] + dp[index-1][e]) % mod;
            dp[index][o] = dp[index-1][i];
            dp[index][u] = (dp[index-1][i] + dp[index-1][o] ) % mod;
        }

        long long ans = 0;
        for (int i = 0; i < 5; i++) {
            ans = (ans + dp[n][i]) % mod;
        }

        return static_cast<int>(ans); 

    }
};
