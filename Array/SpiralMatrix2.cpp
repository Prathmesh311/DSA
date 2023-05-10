class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int startRow = 0;
        int startCol = 0;
        int endRow = n-1;
        int endCol = n-1;
        int totalElements = n * n;

        int count = 0;

        while(count < totalElements){
            //Fill 1st row
            for(int i=startCol; count < totalElements && i <= endCol; i++){
                matrix[startRow][i] = count+1;
                count++;
            }
            startRow++;

            //Fill last col
            for(int i=startRow; count < totalElements && i <= endRow; i++){
                 matrix[i][endCol] = count+1;
                count++;
            }
            endCol--;

            //Fill last row
            for(int i=endCol; count < totalElements && i >= startCol; i--){
                 matrix[endRow][i] = count+1;
                count++;
            }
            endRow--;

            //Fill 1st col
            for(int i=endRow; count < totalElements && i >= startRow; i--){
                 matrix[i][startCol] = count+1;
                count++;
            }
            startCol++;
        }

        return matrix;
    }
};
