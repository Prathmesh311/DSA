class Solution {
public:

    bool DFS(vector<vector<int>>& graph, int *visited, int node, int parent, int color){
        //make node visited
        visited[node] = color;  //1 or 2 means visited

        for(int nbr : graph[node]){
            if(visited[nbr] == 0){
                bool subprob = DFS(graph, visited, nbr, node, 3-color);   //toggeling color 1 to 2 and vise varsa
                if(subprob == false){
                    return false;
                }
            }
            else if(nbr!=parent && color == visited[nbr]){
                return false;
            }
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int visited[101] = {0};   //0 - not visited; 1 = visited and color 1; 2 - visited and color 2

        int color = 1;
        for(int i=0; i < graph.size(); i++){
            if(visited[i] == 0){
                bool ans = DFS(graph, visited, i, i, color);
                if(ans == false){
                    return false;
                }
                color = 3 - color;   //toggeling color 1 to 2 and vise varsa
            } 
        }
        
        return true;
    }
};
