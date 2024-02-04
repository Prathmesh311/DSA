class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        vector<vector<int>> newGrid(image.size(), vector<int>(image[0].size(), 0));
        vector<vector<int>> used(image.size(), vector<int>(image[0].size(), 0));
        
        int row = 1;
        int col = 1;
        
        while(row + 1 < image.size()){
            while(col + 1 < image[0].size()){
                if(abs(image[row-1][col] - image[row][col]) > threshold || 
                   abs(image[row][col-1] - image[row][col]) > threshold || 
                   abs(image[row][col+1] - image[row][col]) > threshold || 
                   abs(image[row+1][col] - image[row][col]) > threshold ||
                   
                  abs(image[row-1][col-1] - image[row-1][col]) > threshold ||
                  abs(image[row-1][col+1] - image[row-1][col]) > threshold ||
                   
                  abs(image[row-1][col-1] - image[row][col-1]) > threshold ||
                  abs(image[row+1][col-1] - image[row][col-1]) > threshold ||
                   
                  abs(image[row+1][col-1] - image[row+1][col]) > threshold ||
                  abs(image[row+1][col+1] - image[row+1][col]) > threshold ||
                   
                   abs(image[row-1][col+1] - image[row][col+1]) > threshold ||
                  abs(image[row+1][col+1] - image[row][col+1]) > threshold){
                    col++;
                    continue;
                }
                int sum = image[row-1][col-1] + image[row-1][col] + image[row-1][col+1] +
                            image[row][col-1] + image[row][col] + image[row][col+1] +
                            image[row+1][col-1] + image[row+1][col] + image[row+1][col+1];
                
                int avg = sum / 9;
                
                for(int i = row-1; i <= row+1; i++){
                    for(int j = col-1; j <= col+1; j++){
                        newGrid[i][j] += avg;
                        used[i][j] += 1;
                    }
                }
                col++;
            }
            col = 1;
            row++;
        }
        
        for(int i=0; i < newGrid.size(); i++){
            for(int j=0; j < newGrid[0].size(); j++){
                if(used[i][j] == 0){
                    newGrid[i][j] = image[i][j];
                }else{
                    newGrid[i][j] = newGrid[i][j]/used[i][j];
                }
            }
        }
        
        return newGrid;
    }
};
