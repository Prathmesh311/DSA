class Solution {
public:
    void traverse(unordered_map<int, vector<int>> &adj, vector<int> &visited, int currNode){
        if(visited[currNode] == 1){
            return;
        }

        visited[currNode] = 1;

        for(int nextNode : adj[currNode]){
            traverse(adj, visited, nextNode);
        }
        
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> visited(n, 0); 

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int connectedComponents = 0;
        for(int i=0; i < n; i++){
            if(visited[i] == 0){
                traverse(adj, visited, i);
                connectedComponents++;
            }
        }

        return connectedComponents;
    }
};
