class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, vector<int> &visited, int node, int prevNode){
        if(visited[node] == 1) {
            return true;
        }

        visited[node] = 1;
        
        for(int nextNode: adj[node]){
            if(nextNode != prevNode && 
            hasCycle(adj, visited, nextNode, node)){
                return true;
            }
        }
        return false;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);

        for(auto p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        if(hasCycle(adj, visited, 0, -1)){
            return false;
        }

        for(int i=0; i < n; i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }
};
