#include<iostream>
using namespace std;

struct trie
{
    trie *next[26];

    trie(){
        for(int i=0; i < 26; i++){
            next[i] = NULL;
        }
    }
};

trie *root;

void insertInTrie(string s){
    trie *curr = root;

    for(int i=0; i < s.size(); i++){
        if(curr->next[s[i] - 'a'] == NULL){
            curr->next[s[i] - 'a'] = new trie();
        }

        curr = curr->next[s[i] - 'a'];
    }
    cout<<"inserted "<<s<<endl;
}

bool searchInTrie(string s){
    trie * curr = root;

    for(int i=0; i < s.size(); i++){
        if(curr->next[s[i] - 'a'] == NULL){
            return false;
        }

        curr = curr->next[s[i] - 'a'];
    }

    return true;
}

int main(){
    root = new trie();
    string text = "abaacabca";
    string pattern = "aaca";
  
    for(int i=0; i < text.size(); i++){
        insertInTrie(text.substr(i));
    }

    if(searchInTrie(pattern)){
        cout<<"Yes found!";
    }else{
        cout<<"Not found";
    }

    return 0;
}