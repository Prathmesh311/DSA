class Solution {
public:
    int minPath(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row, int col) {
        if(row >= triangle.size() || col >= triangle[row].size()){
            return 0;
        }

        if(dp[row][col]  != INT_MAX){            //if already counted return value
            return dp[row][col];
        }


        int currSum = minPath(triangle, dp, row+1, col);     //passing to same col in next row
        int nextSum = minPath(triangle, dp, row+1, col+1);   //passing to next col in next row

        dp[row][col] = min(currSum, nextSum) + triangle[row][col];   //storing min path sum untill this position

        return dp[row][col];
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(201 , vector<int> (201, INT_MAX));

        int minPathSum = minPath(triangle, dp, 0, 0);
        return minPathSum;
    }
};
