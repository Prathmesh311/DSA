class Solution {
public:
    bool bfs(unordered_map<int, vector<int>> &adj,  unordered_map<int, int> &groupCountMap, int node){
        queue<int> q;
        unordered_map<int, int> groupMap;

        q.push(node);
        groupMap[node] = 1;

        int minNode = node;
        int maxGroup = 1;

        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            int currGroup = groupMap[currNode];
            minNode = min(minNode, currNode);
            maxGroup = max(maxGroup, currGroup);

            for(auto next : adj[currNode]){
                if(groupMap.find(next) != groupMap.end()){
                    if(abs(groupMap[next] - currGroup) != 1){
                        return false;
                    }
                }else{
                    groupMap[next] = currGroup + 1;
                    q.push(next);
                }
            }
        }

        groupCountMap[minNode] = max(groupCountMap[minNode], maxGroup);
        return true;

    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> groupCountMap;


        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=1; i <= n; i++){
            if(!bfs(adj, groupCountMap, i)){
                return -1;
            }
        }

        int result = 0;
        for(auto p : groupCountMap){
            result += p.second;
        }

        return result;
    }
};
