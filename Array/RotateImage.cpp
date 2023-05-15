class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;

        while(left < right){
            int n = right-left;

            for(int i=left; i < left + n; i++){
                int diff = i-left;

                int row = top;
                int col = i;
                int temp1 = matrix[row][col];  //picking element
               
                row = i;
                col = right;
                int temp2 = matrix[row][col];
                matrix[row][col] = temp1;      //swapping with last col

                row = bottom;
                col = right-diff;
                temp1 = matrix[row][col];
                matrix[row][col] = temp2;      //swapping with last row

                row = bottom-diff;
                col = left;
                temp2 = matrix[row][col];
                matrix[row][col] = temp1;      //swapping with first col

                row = top;
                col = i;
                matrix[row][col] = temp2;
            }

            left++;
            right--;
            top++;
            bottom--;
        }
      
    }
};
