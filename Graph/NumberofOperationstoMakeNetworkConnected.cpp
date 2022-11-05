class Solution {
public:

    void connectedComponents(int src, vector<bool>& visited,  map<int, vector<int>>& Graph){

        visited[src] = true;

        for(int nbr: Graph[src]){
            if(!visited[nbr]){
                connectedComponents(nbr, visited, Graph);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        map<int, vector<int>> Graph;
        vector<bool> visited(n, false);

        if(connections.size() < n-1){     //if unsufficient edges return -1;
            return -1;
        }

        for(auto p: connections){        // creating adjecency list
            Graph[p[0]].push_back(p[1]);
            Graph[p[1]].push_back( p[0]);
        }


        int count = 0;                   //number of islands
        
        for(int i=0; i < n; i++){

            if(!visited[i]){
                connectedComponents(i, visited, Graph);
                count++;
            }
        }

        
        return count-1;
    }
};
