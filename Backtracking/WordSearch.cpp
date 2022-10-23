class Solution {
public:
    
    bool wordSearch(vector<vector<char>>& mat,string word, int i, int j, int s){
        //Base case
        if(mat[i][j] == word[s] && word[s+1] == '\0'){
            return true;
        }
        
        
        if(mat[i][j] != word[s]){
            return false;
        }
        
        //Mark Element as visited
        mat[i][j] = '#';
        
        //Recursive case
        bool left = false, right=false, up=false, down=false;
        
        if(j > 0){
            left = wordSearch(mat, word,  i, j-1, s+1);
        }
        
        if(j < mat[0].size()-1 ){
            right = wordSearch(mat, word,   i, j+1, s+1);   
        }
        
        if(i > 0 ){ 
            up = wordSearch(mat, word,  i-1, j, s+1);           
        }
        
        if(i < mat.size()-1){    
            down = wordSearch(mat, word,  i+1, j, s+1);       
        }
        
        mat[i][j] = word[s];
        
        return left || right || up || down;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        bool ans = false;
       
        vector<string> path;
         for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){  
                   if(wordSearch(board, word, i, j, 0)){
                       return true;
                   }
                   
                }
            }
        }
        
        return ans;
    }
};
