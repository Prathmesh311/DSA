class Solution {
public:
    int map[201][201] = {0};
    int flipMap[201][201] = {0};

    //Method to find the region is surrounded or not
    bool traverseIsland(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){  //return true if region cannot be surrounded
            return true;
        }

        if(grid[i][j] == 'X'){
            return false;
        }

        if(map[i][j] == 1){
            return false;
        }

        map[i][j] = 1;

        bool down = traverseIsland(grid, i+1, j);         //DFS in all 4 directions
        bool up = traverseIsland(grid, i-1, j);
        bool right = traverseIsland(grid, i, j+1);
        bool left = traverseIsland(grid, i, j-1);

        
        if(down || up || right || left){                 //If any 1 direction is open then return true
            return true;
        }
        return false;
    }

    //Method to flip the surrounded region from 'O' to 'X'
    void distroyRegion(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == 'X'){
            return;
        }

        if(flipMap[i][j] == 1){
            return;
        }

        grid[i][j] = 'X';    //fliping the position
        flipMap[i][j] = 1;

        distroyRegion(grid, i+1, j);
        distroyRegion(grid, i-1, j);
        distroyRegion(grid, i, j+1);
        distroyRegion(grid, i, j-1);
       
    }

    void solve(vector<vector<char>>& board) {

        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                if(board[i][j] == 'O' && map[i][j] == 0){
                    bool notSurrounded = traverseIsland(board, i, j);  //check if region is surrounded
                    if(!notSurrounded){                                //If surrounded then flip the region
                        distroyRegion(board, i, j);
                    }
                }
            }
        }

    }
};
