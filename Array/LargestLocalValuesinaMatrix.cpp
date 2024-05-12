class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size()-2, vector<int>(grid[0].size()-2));

        for(int i=0; i < grid.size()-2; i++){
            for(int j = 0; j < grid[0].size()-2; j++){
                for(int r = i; r < i+3; r++){
                    for(int c = j; c < j+3; c++){
                        res[i][j] = max(res[i][j], grid[r][c]);
                    }
                }
            }
        }

        return res;
    }
};
