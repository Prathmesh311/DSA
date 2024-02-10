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

    //Method 1: DFS
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


   //Method 2: BFS
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> color(graph.size(), -1);
        vector<int> visited(graph.size(), 0);


        for(int i=0; i < graph.size(); i++){
            if(visited[i] == 0){

                q.push(i);
                color[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    visited[node] = 1;

                    for(int nextNode : graph[node]){
                        if(visited[nextNode] == 0){
                            q.push(nextNode);
                            color[nextNode] = 1 - color[node];
                        }else if(color[node] == color[nextNode]){
                            return false;
                        }
                    }
                }
             }
        }

        return true;
    }

};
