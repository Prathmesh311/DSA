class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> visited(10, vector<int>(10, 0));
        vector<int> spiralPath;

        int startRow = 0;
        int startCol = 0;
        int endRow = matrix.size()-1;
        int endCol = matrix[0].size()-1;
        int totalElements = matrix.size() * matrix[0].size();

        int count = 0;
        
        while(count < totalElements){
            //Print 1st row
            for(int i=startCol; count < totalElements && i <= endCol; i++){
                spiralPath.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            //print last col
            for(int i=startRow; count < totalElements && i <= endRow; i++){
                spiralPath.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            //print last row
            for(int i=endCol; count < totalElements && i >= startCol; i--){
                spiralPath.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            //print 1st col
            for(int i=endRow; count < totalElements && i >= startRow; i--){
                spiralPath.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }

        return spiralPath;
    }
};
