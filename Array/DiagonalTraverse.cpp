class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int currRow = 0;
        int currCol= 0;

        bool goingUp = true;

        vector<int> result;

        while(result.size() < rows * cols){
            if(goingUp){
                while(currRow >= 0 && currCol < cols){
                    result.push_back(mat[currRow][currCol]);

                    currRow -= 1;
                    currCol += 1;
                }

                if(currCol < cols){
                    currRow += 1;
                }else{
                    currRow += 2;
                    currCol -= 1;
                }

                goingUp = false;
            }else{
                while(currRow < rows && currCol >= 0){
                    result.push_back(mat[currRow][currCol]);

                    currRow += 1;
                    currCol -= 1;
                }

                if(currRow < rows){
                    currCol += 1;
                }else{
                    currCol += 2;
                    currRow -= 1;
                }
                goingUp = true;
            }
        }

        return result;
    }
};
