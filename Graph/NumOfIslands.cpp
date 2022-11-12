class Solution {
public:
    int visited[301][301];
    void islandTraversal(vector<vector<char>>& grid, int sr, int sc){
        if(sr<0 || sc<0 || sr>=grid.size() || sc>=grid[0].size() || visited[sr][sc] == 1 || grid[sr][sc] == '0'){
            return;
        }


        visited[sr][sc] = 1;

        islandTraversal(grid,  sr-1, sc);
        islandTraversal(grid,  sr, sc-1);
        islandTraversal(grid, sr+1, sc);
        islandTraversal(grid,  sr, sc+1);

        return;

    }

    int numIslands(vector<vector<char>>& grid) {

        for(int i=0; i < 301; i++){
            for(int j=0; j < 301; j++){
                visited[i][j] = 0;
            }
        }

        int numIslands = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'  && visited[i][j] == 0){
                    islandTraversal(grid, i, j);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};
