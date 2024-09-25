class Trie{
public:
    Trie *next[10];
    bool end;

    Trie(){
        for(int i=0; i < 10; i++){
            next[i] = NULL;
        }
        end = false;
    }
};

class Solution {
private:
    Trie* root = new Trie();
    
    void insert(string num){
        Trie *curr = root;

        for(char c : num){
            if(curr->next[c-'0'] == NULL){
                curr->next[c-'0'] = new Trie();
            }
            curr = curr->next[c-'0'];
        }

        curr->end = true;
    }

    int findPrefix(string num){
        Trie *curr = root;

        int prefixLen = 0;

        for(char c : num){
            if(curr == NULL || curr->next[c-'0'] == NULL){
                return prefixLen;
            }

            curr = curr->next[c-'0'];
            prefixLen++;
        }

        return prefixLen;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int longestPrefix = INT_MIN;

        for(int num : arr2){
            insert(to_string(num));
        }

        for(int num : arr1){
            int currPrefix = findPrefix(to_string(num));
            longestPrefix = max(longestPrefix, currPrefix);
        }

        return longestPrefix;
    }
};
