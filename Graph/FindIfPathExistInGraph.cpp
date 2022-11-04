class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int, vector<int>> Graph;

        for(auto e: edges){                         //Created adjecency list using given edges.
            Graph[e[0]].push_back(e[1]);
            Graph[e[1]].push_back(e[0]);
        }

        bool visited[200001] = {false};
        queue<int> q;
        
        q.push(source);
        visited[source] =true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nbr : Graph[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        
        return visited[destination];
        
        
    }
};
