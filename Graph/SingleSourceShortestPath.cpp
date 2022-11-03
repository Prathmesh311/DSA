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

        void shortestPathForEachNode(int src){
            map<int, int> dist;
            queue<int> q;

            for(auto nodePair : l){
                int node = nodePair.first;
                dist[node] = INT8_MAX;
            }

            q.push(src);
            dist[src] = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int nbr : l[node]){
                    if(dist[nbr] == INT8_MAX){
                        q.push(nbr);
                        dist[nbr] = dist[node] + 1;
                    }
                }
            }

            for(auto p: dist){
                cout<<"Node "<<p.first<<" is at dist "<<p.second<<endl;
            }

            
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

    g.shortestPathForEachNode(0);
    return 0;
}