class Solution {
public:
    void traverse(vector<vector<int>> &adj, vector<int> &visited, int node){
        if(visited[node] == 1){
            return;
        }
        visited[node] = 1;

        for(int nextNode : adj[node]){
            traverse(adj, visited, nextNode);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);
        int components = 0;

        for(auto p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        for(int i=0; i < n; i++){
            if(!visited[i]){
                traverse(adj, visited, i);
                components++;
            }
        }

        return components;
    }
};
