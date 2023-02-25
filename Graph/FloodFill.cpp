class Solution {
public:
    int map[51][51] = {0};

    void coloring(vector<vector<int>> & image, int sr, int sc, int currColor, int color){
        if(sr >= image.size() || sc >= image[0].size() || sr < 0 || sc < 0){ //checking boundaries of matrix
            return;
        }

        if(map[sr][sc] == 1){            //if node is visited previously then return
            return;
        }

        if(image[sr][sc] != currColor){  //if Currnode of diff color return
            return;
        }

        map[sr][sc] = 1;
        image[sr][sc] = color;
        

        coloring(image, sr+1, sc, currColor, color);    //DFS over all 4 directions
        coloring(image, sr-1, sc, currColor, color);
        coloring(image, sr, sc+1, currColor, color);
        coloring(image, sr, sc-1, currColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        coloring(image, sr, sc, image[sr][sc], color);

        return image;
    }
};
