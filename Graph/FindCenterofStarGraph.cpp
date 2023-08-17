class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1, vector<int>());

        for(int i=0; i < edges.size(); i++){
            adj[edges[i][0]-1].push_back(edges[i][1]);
            adj[edges[i][1]-1].push_back(edges[i][0]);
        }

        for(int i=0; i < adj.size(); i++){
            if(edges.size() == adj[i].size()){
                return i+1;
            }
        }
        return 0;
    }
};
