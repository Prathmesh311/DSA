class Solution {
public:
    int visited[101][101];
    int perimeterFinder(vector<vector<int>>& grid, int sr, int sc){
        //Base condition
        if(sr<0 || sc<0 || sr>=grid.size() || sc>=grid[0].size()){ //checking boundaries of matrix
            return 1;
        }

        if(grid[sr][sc] == 0){     //if Currnode 0 then return
            return 1;
        }

        if(visited[sr][sc] == 1){           //if node is visited previously then return
            return 0;
        }

        visited[sr][sc] = 1;

        //DFS in all 4 directions
        return  perimeterFinder(grid, sr-1, sc) +  
                perimeterFinder(grid, sr, sc-1) +
                perimeterFinder(grid, sr+1, sc) +
                perimeterFinder(grid, sr, sc+1);

    }


    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0; i < 101; i++){
            for(int j=0; j < 101; j++){
                visited[i][j] = 0;
            }
        }
        
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return perimeterFinder(grid, i, j);
                }
            }
        }
        return 0;

    }
};
