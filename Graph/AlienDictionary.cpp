/*

words = ["acd", "adr", "cdb"]
o/p = "acdbr"

adj = {{a, [c, d]}, {c, [d]}, {d, [r, b]}, {r, [b]}}
indegree = {{a, 0}, {c, 1}, {}}

Implementation;
    -> create adj map
    -> crate inDegree
    -> do BFS (using Topological sort)
    -> if Possible to visit all return result / return ""
*/


class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        queue<char> q;
        string result = "";

        for(string word : words){
            for(char c : word){
                if(indegree.find(c) == indegree.end()){
                    indegree[c] = 0;
                }
            }
        }

        for(int i=0; i < words.size()-1; i++){
            int j = 0;
            for(; j < words[i].size() && j < words[i+1].size(); j++){
                if(words[i][j] != words[i+1][j]){
                   adj[words[i][j]].push_back(words[i+1][j]);
                   indegree[words[i+1][j]] += 1;
                   break;
                }
            }

            if(j >= words[i+1].size() && j < words[i].size()){
                return "";
            }
        }

        for(auto p : indegree){
            if(p.second == 0){
                q.push(p.first);
            }
        }

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i < size; i++){
                char c = q.front();
                q.pop();

                result += c;

                for(char next : adj[c]){
                    indegree[next] -= 1;

                    if(indegree[next] == 0){
                        q.push(next);
                    }
                }
            }
        }

        for(auto p : indegree){
            if(p.second > 0){
                return "";
            }
        }

        return result;
    }
};
