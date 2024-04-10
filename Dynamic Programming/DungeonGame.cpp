class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();

        for(int i=rows-1; i >= 0; i--){
            for(int j=cols-1; j >= 0; j--){
                if (i == rows - 1 && j == cols - 1) {
                    // Base case: the princess's room
                    dungeon[i][j] = std::max(1, 1 - dungeon[i][j]);
                } else if (i == rows - 1) {
                    // Last row: can only move right
                    dungeon[i][j] = std::max(1, dungeon[i][j + 1] - dungeon[i][j]);
                } else if (j == cols - 1) {
                    // Last column: can only move down
                    dungeon[i][j] = std::max(1, dungeon[i + 1][j] - dungeon[i][j]);
                } else {
                    // Interior cells: can move right or down
                    int right = std::max(1, dungeon[i][j + 1] - dungeon[i][j]);
                    int down = std::max(1, dungeon[i + 1][j] - dungeon[i][j]);
                    dungeon[i][j] = std::min(right, down);
                }
            }
        }

        return dungeon[0][0];
    }
};
