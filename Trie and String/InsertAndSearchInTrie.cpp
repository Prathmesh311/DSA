#include<iostream>
using namespace std;

struct trie
{
    trie *next[26];
    bool ended;

    trie(){
        for(int i=0; i < 26; i++){
            next[i] = NULL;
        }
        ended = false;
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
    curr->ended = true;
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

    return curr->ended;
}

int main(){
    root = new trie();
    insertInTrie("Prathmesh");
    insertInTrie("Swapnil");
    insertInTrie("Ankush");
    insertInTrie("kaustubh");


    if(searchInTrie("Prathmesh")){
        cout<<"Yes found!";
    }else{
        cout<<"Not found";
    }

    return 0;
}