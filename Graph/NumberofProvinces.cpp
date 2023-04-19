class Solution {
public:
    void numOfProvince(vector<vector<int>>& adj, vector<int>& visited, int node){
        //If no furthur connections available return
        if(adj[node].size() == 0){
            return;
        }

        //memo
        visited[node] = 1;

        for(int nextNode: adj[node]){
            if(visited[nextNode] == 0){
                numOfProvince(adj, visited, nextNode);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj;
        vector<int> visited(isConnected.size(), 0);

        //Create adjecency list
        for(int i=0; i < isConnected.size(); i++){
            vector<int> list;
            for(int j=0; j < isConnected[i].size(); j++){
                if(isConnected[i][j] == 1 && i != j){
                    list.push_back(j);
                }
            }
            adj.push_back(list);
        }

        //Traversing through graph
        int totalProvince = 0;
        for(int i=0; i < isConnected.size(); i++){
            if(visited[i] == 0){
                numOfProvince(adj, visited, i);
                totalProvince++;
            }
        }

        return totalProvince;
    }
};
