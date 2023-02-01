struct trie
{
    trie *next[26];
    int childs;               //To keep track childs from given node
    bool ended;

    trie(){
        for(int i=0; i < 26; i++){
            next[i] = NULL;
        }
        ended = false;
        childs = 0;
    }
};


void insertInTrie(trie *root, string s){
    trie *curr = root;

    for(int i=0; i < s.size(); i++){
        if(curr->next[s[i] - 'a'] == NULL){
            curr->next[s[i] - 'a'] = new trie();
            curr->childs++;       //update the number of childs in node
        }
    
        curr = curr->next[s[i] - 'a'];
    }
    curr->ended = true;
}

string  searchInTrie(trie *root, string s, string ans){
    trie * curr = root;
    
    for(int i=0; i < s.size(); i++){
        if(curr->ended == false && curr->childs == 1){  //if node has only 1 child add it to Ans string
            ans.push_back(s[i]);
            curr = curr->next[s[i] - 'a'];
        }
        else{                                           //else data is different and prefix is finished
            return ans;
        }  
    }

    return ans;
}


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie *root = new trie();
        for(int i=0; i < strs.size(); i++){
            insertInTrie(root, strs[i]);          //first add all string to Trie
        }

        string ans = "";
        return searchInTrie(root, strs[0], ans);  
        
    }
};
