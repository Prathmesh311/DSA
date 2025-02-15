class Trie {
public:
    Trie *next[26];
    bool end;
        
    Trie() {
        for(int i=0; i < 26; i++){
            next[i] = NULL;
        }
        end = false;
    }
    
    void insert(string word) {
        Trie *currNode = this;

        for(char c : word){
            if(currNode->next[c - 'a'] == NULL){
                currNode->next[c - 'a'] = new Trie();
            }

            currNode = currNode->next[c - 'a'];
        }
        currNode->end = true;
    }
    
    bool search(string word) {
        Trie *currNode = this;

        for(char c : word){
            if(currNode->next[c - 'a'] == NULL){
                return false;
            }

            currNode = currNode->next[c - 'a'];
        }
        
        return currNode->end;
    }
    
    bool startsWith(string prefix) {
        Trie *currNode = this;

        for(char c : prefix){
            if(currNode->next[c - 'a'] == NULL){
                return false;
            }

            currNode = currNode->next[c - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
