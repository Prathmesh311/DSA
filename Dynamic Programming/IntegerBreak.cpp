class Solution {
public:
    int breaker(int mainNum, int num, vector<int> &dp){
        if(mainNum < 0){
            return 0;
        }

        if(mainNum == 0){
            return 1;
        }

        if(dp[mainNum] != 0){
            return dp[mainNum];
        }

        int maxMultiple = 0;
        for(int i=num; i > 0; i--){
            int multiple = i * breaker(mainNum - i, num, dp);
            maxMultiple = max(maxMultiple, multiple);
        }

        return dp[mainNum] = maxMultiple;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1, 0);


        int num = n / 2;
        if(n % 2 == 1){
            num++;
        }

        return breaker(n, num, dp);
    }
};
