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
        }


        void topoSortBFS(int numNodes){

            int *inDegree = new int[numNodes];

            for(int i=0; i < numNodes; i++){
                inDegree[i] = 0;
            }

            for(auto p : adj){
                for(int nbr : p.second){
                    inDegree[nbr] = inDegree[nbr] + 1;    //Count the number of nodes on which currNode is dependent on 
                }
            }

            //BFS
            map<int, bool> visited;
            queue<int> q;
            
            for(auto i: adj){
                visited[i.first] = false;
            }
    
            for(int i=0; i < numNodes; i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                cout<<node<<" ";

                for(int nbr : adj[node]){
                    if(!visited[nbr]){
                        inDegree[nbr]--;
                        if(inDegree[nbr]==0){
                            q.push(nbr);
                        }
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
    

    g.topoSortBFS(4);
    return 0;
}