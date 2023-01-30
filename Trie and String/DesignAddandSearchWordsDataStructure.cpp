class WordDictionary {
private:
    WordDictionary *next[26];
    bool ended;
public:
    WordDictionary() {
         for(int i=0; i < 26; i++){
            next[i] = NULL;
        }
        ended = false;
    }
    
    void addWord(string s) {
         WordDictionary *curr = this;

        for(int i=0; i < s.size(); i++){
            if(curr->next[s[i] - 'a'] == NULL){
                curr->next[s[i] - 'a'] = new WordDictionary();
            }

            curr = curr->next[s[i] - 'a'];
        }
        curr->ended = true;
        cout<<"inserted "<<s<<endl;
    }

    bool search(string s){
        return trieSearch(s, this);
    }

    bool trieSearch(string s, WordDictionary *curr) {  //helper 

        for(int i=0; i < s.size(); i++){
            if(s[i] != '.' && curr->next[s[i] - 'a'] == NULL){
                return false;
            }
            else if(s[i] == '.'){        //for '.' search for every char ans traverrse
                int j=0;
                WordDictionary * temp = curr;
                for(; j < 26; j++){
                    if(temp->next[j] != NULL){
                        curr = temp->next[j];
                        if(trieSearch(s.substr(i+1), curr)){
                            return true;
                        }
                    }
                }
                if(j==26){
                    return false;
                }
                continue;
            }
            

            curr = curr->next[s[i] - 'a'];
        }

        return curr->ended;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
