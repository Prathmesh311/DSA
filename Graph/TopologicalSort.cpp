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
        }

        void connectedComponent(int src, map<int, bool>& visited, list<int>& ordering){
            
            //cout<<src<<" ";
            visited[src] = true;

            for(int nbr : l[src]){
                if(!visited[nbr]){
                    connectedComponent(nbr, visited, ordering);
                }
            }

            ordering.push_front(src);
        }

        void topoSort(int src){
            map<int, bool> visited;
            list<int> ordering;
            
            for(auto i: l){
                visited[i.first] = false;
            }
    


            for(auto p : l){
                int node = p.first;
                if(!visited[node]){
                    connectedComponent(node, visited, ordering);
                }
            }

            for(int node : ordering){
                cout<<node<<" ";
            }
            
        }
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,2);
    

    g.topoSort(0);
    return 0;
}