class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        int visited[n+1];
        queue<pair<int, int>> q;

        for(auto edge: dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            visited[edge[0]] = 0;
            visited[edge[1]] = 0;
        }

        for(int i=1; i <= n; i++){
            if(visited[i] == 0){
                q.push({i, 1});

                while(!q.empty()){
                    pair edge = q.front();
                    int node = edge.first;
                    int color = edge.second;

                    q.pop();
                    visited[node] = color;

                    for(int nbr : adj[node]){
                        if(visited[nbr] == 0){
                            q.push({nbr, 3-color}); //toggeling color and pushing to queue
                        }
                        else if(node!=nbr && visited[nbr]==color){      //if same color for nebouring nodes return false as it's not bipartite
                            return false;
                        }
                    }
                }
            }
        }

        

        return true;
    }
};
