class Solution {
public:
    int numOfNodes = 0;
    int numOfEdges = 0;
   
    void traversal(vector<vector<int>> adj, vector<int>& visited, int node, int parent){
        if(visited[node] == 1){
            return;
        }
        
        numOfNodes++;
        numOfEdges += adj[node].size();    //count the nodes and edges of connected component
        
        visited[node] = 1;
        
        for(int i=0; i < adj[node].size(); i++){
            if(visited[adj[node][i]] == 0){
                traversal(adj, visited, adj[node][i], parent);
            }  
        }
    }
    
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> visited(51, 0);
        
        for(int i=0; i < edges.size(); i++){            //create adjecency list
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        int ans = 0;
        for(int i=0; i < n; i++){
            if(visited[i] == 0){
                traversal(adj, visited, i, i);
                
                if(numOfEdges == (numOfNodes * (numOfNodes-1))){   //if this condition satifies then component is complete
                    ans++;
                }
                numOfNodes = 0;
                numOfEdges = 0;   
            }
        }
        return ans;
    }
};
