class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> cost(n, 0); // Allocate based on the number of nodes
        vector<vector<pair<int, double>>> adj(n); // Allocate based on the number of nodes

        queue<int> q;

        for(int i=0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        q.push(start_node);
        cost[start_node] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto p : adj[node]){
                double currCost = cost[node] * p.second;
                
                if(currCost > cost[p.first]){
                    cost[p.first] = max(cost[p.first], currCost);
                    q.push(p.first);
                }
            }
        }

        return cost[end_node];
    }
};
