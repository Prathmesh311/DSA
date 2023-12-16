class Solution {
public:

    void dfs(vector<vector<int>>& heights, int row, int col, set<pair<int, int>>  &visited, int prevHeight){
        if(row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size() || heights[row][col] < prevHeight){
            return;
        }

        if(visited.find({row, col}) != visited.end()){
            return;
        }

        visited.insert({row, col});

        dfs(heights, row-1, col, visited, heights[row][col]);
        dfs(heights, row+1, col, visited, heights[row][col]);
        dfs(heights, row, col-1, visited, heights[row][col]);
        dfs(heights, row, col+1, visited, heights[row][col]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int rows = heights.size();
        int cols = heights[0].size();

        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;


        for(int col = 0; col < cols; col++){
            dfs(heights, 0, col, pacific, heights[0][col]);
            dfs(heights, rows-1, col, atlantic, heights[rows-1][col]);
        }

        for(int row = 0; row < rows; row++){
            dfs(heights, row, 0, pacific, heights[row][0]);
            dfs(heights, row, cols-1, atlantic, heights[row][cols-1]);
        }

        for(int i=0; i < rows; i++){
            for(int j=0; j < cols; j++){
                if((pacific.find({i, j}) != pacific.end()) && (atlantic.find({i, j}) != atlantic.end())){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
