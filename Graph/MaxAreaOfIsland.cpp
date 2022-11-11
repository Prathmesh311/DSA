class Solution {
public:
    int visited[51][51];
    int areaFinder(vector<vector<int>>& grid, int sr, int sc){
        //Base condition
        if(sr<0 || sc<0 || sr>=grid.size() || sc>=grid[0].size()){ //checking boundaries of matrix
            return 0;
        }

        if(grid[sr][sc] == 0){     //if Currnode of diff color return
            return 0;
        }

        if(visited[sr][sc] == 1){           //if node is visited previously then return
            return 0;
        }

        visited[sr][sc] = 1;
     
        //DFS in All 4 directions
        return  areaFinder(grid, sr-1, sc) +  
                areaFinder(grid, sr, sc-1) +
                areaFinder(grid, sr+1, sc) +
                areaFinder(grid, sr, sc+1) + 1;  //added 1 for currNode

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0; i < 51; i++){
            for(int j=0; j < 51; j++){
                visited[i][j] = 0;
            }
        }

        int maxArea = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    maxArea = max(maxArea, areaFinder(grid, i, j));
                }
            }
        }
        return maxArea;

    }
};
