#include <iostream>
#include <set>
 
class Solution {
public:
    bool dfs(map<char, set<char>> &adj, vector<char> &dict, map<char, bool> &visited, char c){
        if(visited.find(c) != visited.end()){
            return visited[c];
        }

        visited[c] = true;

        for(char nextC : adj[c]){
            if(dfs(adj, dict, visited, nextC)){
                return true;
            }
        }

        visited[c] = false;
        dict.push_back(c);

        return false;
    }

    string alienDictionary(vector<string>& words) {
        map<char, std::set<char>> adj;
        map<char, bool> visited;
        vector<char> dict;

        for(int i=0; i < words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];

            int minLen = min(word1.size(), word2.size());

            if(word1.size() > word2.size() && word1.substr(0, minLen) == word2.substr(0, minLen)){
                return "";
            }

            for(int j = 0; j < minLen; j++){
                if(word1[j] != word2[j]){
                    adj[word1[j]].insert(word2[j]);
                    break;
                }
            }
        }

        for(auto p : adj){
            if(dfs(adj, dict, visited, p.first)){
                return "";
            }
        }

        string ans = "";

        for(int i = dict.size()-1; i >=0; i--){
            ans += dict[i];
        }

        return ans;
    }
};
