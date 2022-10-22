class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[100][100] = {0};
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        for(int i=0; i < m; i++){
            for( int j=0; j < n; j++){
                
                if(i==0 && j==0){
                    if(obstacleGrid[i][j] != 1){
                        dp[i][j] = 1;
                    }
                    else{
                        return 0;
                    }
                }
                
                else if(i == 0){
                    if(dp[i][j-1] != 0 && obstacleGrid[i][j] != 1){
                        dp[i][j] = 1;
                    }else{
                         dp[i][j] = 0;
                    }
                }
                else if(j == 0){
                    if(dp[i-1][j] != 0 && obstacleGrid[i][j] != 1){
                        dp[i][j] = 1;
                    }else{
                         dp[i][j] = 0;
                    }
                }
                else{
                    if(obstacleGrid[i][j] != 1){
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        
        
        return dp[m-1][n-1];
    }
};
