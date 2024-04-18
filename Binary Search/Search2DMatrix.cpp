class Solution {
public:
    bool search(vector<vector<int>>& matrix, int row, int target) {
        int start = 0;
        int end = matrix[row].size()-1;

        while(start <= end){
            int mid = (start + end)/2;

            if(matrix[row][mid] == target){
                return true;
            }

            if(matrix[row][mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return false;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        for(int i=0; i < matrix.size(); i++){
            if(matrix[i][0] <= target && target <= matrix[i][cols-1]){
                return search(matrix, i, target);
            }
        }
        
        return false;
    }
};
