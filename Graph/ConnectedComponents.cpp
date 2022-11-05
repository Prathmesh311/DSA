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

        void connectedComponent(int src, map<int, bool>& visited){
            
            cout<<src<<" ";
            visited[src] = true;

            for(int nbr : l[src]){
                if(!visited[nbr]){
                    connectedComponent(nbr, visited);
                }
            }

        }

        void dfs(int src){
            map<int, bool> visited;
            
            for(auto i: l){
                visited[i.first] = false;
            }
    

            int count = 0;
            for(auto p : l){
                int node = p.first;
                if(!visited[node]){
                    cout<<"Component "<<count<<" ---> ";
                    connectedComponent(node, visited);
                    count++;
                    cout<<endl;
                }
            }
            
            cout<<"Total connected components = "<<count;
        }
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);

    g.addEdge(5,6);
    g.addEdge(6,7);

    g.addEdge(8,8);

    g.dfs(0);
    return 0;
}