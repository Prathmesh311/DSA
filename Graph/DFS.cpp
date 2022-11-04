#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    map<int, list<int>> l;

    public:
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void dfsHelper(int src, map<int, bool>& visited){
            
            cout<<src<<" ";
            visited[src] = true;

            for(int nbr : l[src]){
                if(!visited[nbr]){
                    dfsHelper(nbr, visited);
                }
            }

        }

        void dfs(int src){
            map<int, bool> visited;
            
            for(auto i: l){
                visited[i.first] = false;
            }

            dfsHelper(src, visited);

        }
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.dfs(0);
    return 0;
}