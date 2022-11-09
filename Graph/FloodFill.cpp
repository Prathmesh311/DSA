class Solution {
public:
    int visited[51][51];
    void DFSColorFill(vector<vector<int>>& image, int sr, int sc, int currColor, int color){
        //Base condition
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()){ //checking boundaries of matrix
            return;
        }

        if(image[sr][sc] != currColor){     //if Currnode of diff color return
            return;
        }

        if(visited[sr][sc] == 1){           //if node is visited previously then return
            return;
        }

        visited[sr][sc] = 1;

        image[sr][sc] = color;

        DFSColorFill(image, sr-1, sc, currColor, color);  //DFS over all 4 directions
        DFSColorFill(image, sr, sc-1, currColor, color);
        DFSColorFill(image, sr+1, sc, currColor, color);
        DFSColorFill(image, sr, sc+1, currColor, color);

        return;

    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //int visited[51][51];
        for(int i=0; i < 51; i++){
            for(int j=0; j < 51; j++){
                visited[i][j] = 0;
            }
        }
        int currColor = image[sr][sc];
        DFSColorFill(image, sr, sc, currColor, color);

        return image;
        
    }
};
