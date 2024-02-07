class Solution {
public:
    double dfs(vector<vector<int>> &adj, vector<int> &visited, int &target, int t, int node){
        if(t == 0 || adj[node].size() == 1 && node != 1){
            return node == target;
        }

        visited[node] = 1;
        int notVisited = 0;

        double maxProbability = 0;
        for(int nextNode : adj[node]){
            if(visited[nextNode] == 0){
                maxProbability = max(maxProbability, dfs(adj, visited, target, t-1, nextNode));
                notVisited++;
            }
        }

        return maxProbability * double(1/double(notVisited));
    }


    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1);
        vector<int> visited(n+1, 0);

        if (n == 1) {
            return 1.0;
        }

        for(vector<int> v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        return dfs(adj, visited, target, t, 1);
    }
};
