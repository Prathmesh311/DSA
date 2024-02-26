//Trie data structure for storing the words
class Trie{
public:
    Trie *next[26];
    bool isWord;

    Trie(){
        for(int i=0; i < 26; i++){
            next[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
private:
    Trie* root = new Trie();

    //Insert available words in dictinoary to Trie
    void insert(string word){
        Trie* curr = root;

        for(int i=0; i < word.size(); i++){
            char c = word[i];
            if(curr->next[c - 'a'] == NULL){
                curr->next[c - 'a'] = new Trie();
            }

            curr = curr->next[c -'a'];
        }

        curr->isWord = true;
    }

    //DFS + search word in Trie
    void search(vector<vector<char>>& board, Trie* node, int row, int col, string str, vector<string> &wordPresent){
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()){
            return;
        }

        if(board[row][col] == '#'){
            return;
        }

        char c = board[row][col];

        //If char is not present in trie - return
        if(node->next[c - 'a'] == NULL){
            return; 
        }

        //Go to the curr char node
        node = node->next[c - 'a'];

        //If word ends at char c. add word to found words
        if(node->isWord == true){
            wordPresent.push_back(str+c);
            node->isWord = false;
        }

        //Mark visited pos in board
        board[row][col] = '#';
       
        //DFS - on adjecent positions
        search(board, node, row-1, col, str + c, wordPresent);
        search(board, node, row+1, col, str + c, wordPresent);
        search(board, node, row, col-1, str + c, wordPresent);
        search(board, node, row, col+1, str + c, wordPresent);
        
        //unmark position
        board[row][col] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> wordPresent;
        //insert words into Trie
        for(string word : words){
            insert(word);
        }

        Trie* node = root;

        //For each position do DFS and check if any word is present
        for(int row=0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                search(board, node, row, col, "", wordPresent);
            }
        }

        return wordPresent;
    }
};
