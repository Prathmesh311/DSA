#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    map<int, list<int>> adj;

    public:
        void addEdge(int x, int y){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }


        bool isTree(){

            //BFS
            map<int, bool> visited;
            map<int, int> parent;
            queue<int> q;
            
            for(auto i: adj){
                visited[i.first] = false;
                parent[i.first] = i.first;
            }
    
            int src = 0;

            visited[src] = true;
            q.push(src);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                visited[node] = true;

                for(int nbr : adj[node]){
                    if(visited[nbr] == true && parent[node]!=nbr){
                        return false;
                    }

                    else if(!visited[nbr]){
                        q.push(nbr);
                        parent[nbr] = node;
                        
                    }
                }
            }
            
        }
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(0,3);
    

    if(g.isTree()){
        cout<<"Yes it is a tree!";
    }else{
        cout<<"Not a tree";
    }
    return 0;
}