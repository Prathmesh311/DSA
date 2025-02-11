class NumMatrix {
public:
    vector<vector<int>> prefixSum;

    NumMatrix(vector<vector<int>>& matrix) {

        prefixSum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[0].size(); j++){
                
                int left = j - 1 < 0 ? 0 : prefixSum[i][j-1];
                int up = i - 1 < 0 ? 0 : prefixSum[i-1][j];
                int diag = i - 1 < 0 || j - 1 < 0 ? 0 : prefixSum[i-1][j-1];

                int currVal = matrix[i][j] + left + up - diag;
                prefixSum[i][j] = currVal;
            }

        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = col1 == 0 ? 0 : prefixSum[row2][col1-1];
        int up = row1 == 0 ? 0 : prefixSum[row1-1][col2];
        int diag = row1 == 0 || col1 == 0 ? 0 : prefixSum[row1-1][col1-1];

        return prefixSum[row2][col2] - left - up + diag;
    }
};
