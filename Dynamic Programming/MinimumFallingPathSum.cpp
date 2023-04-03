class Solution {
public:
    int fallingSum(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col){
        if(row >= matrix.size()){
            return 0;
        }

        if(col < 0 || col >= matrix[0].size()){
            return INT_MAX;
        }

        if(dp[row][col] != INT_MAX){          //checking if ans is available
            return dp[row][col];
        }

        int leftDigonal = fallingSum(matrix, dp, row+1, col-1);    //traversing
        int next        = fallingSum(matrix, dp, row+1, col);
        int rightDigonal= fallingSum(matrix, dp, row+1, col+1);

        dp[row][col] = min(leftDigonal, min(next, rightDigonal)) + matrix[row][col];  //storing calculated pathsum

        return dp[row][col];
    } 

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(101, vector<int>(101, INT_MAX));

        int ans = INT_MAX;
        for(int i=0; i < matrix[0].size(); i++){           //interating through 1st row of matrix and calculating minPathSum
            ans = min(ans, fallingSum(matrix, dp, 0, i));
        }
        return ans;
    }
};
