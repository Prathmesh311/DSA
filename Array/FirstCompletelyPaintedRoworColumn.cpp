class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> remRow(col, row);
        vector<int> remCol(row, col);
        
        vector<vector<int>> values(row*col+1, vector<int>(2, 0));  //created array to store index of values in matrix
      
        for(int r=0; r < row; r++){                                //adding index values 
                for(int c=0; c < col; c++){
                    int currNum = mat[r][c];
                    values[currNum][0] = r;
                    values[currNum][1] = c;
                }
            }
        
        for(int i=0; i < arr.size(); i++){                         
            int currNum = arr[i];
            
            int r = values[currNum][0];
            int c = values[currNum][1];
            
            remRow[c]--;                                           //for each value reduce the row and col values
            remCol[r]--;
            if(remRow[c] == 0 || remCol[r] == 0){                  //If row or col fully filled return index of array
                return i;
            }  
        }
        return arr.size()-1;
    }
};
