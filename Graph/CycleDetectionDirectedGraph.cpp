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

        bool cycleFinder(int node, bool *visited, bool *path){

            visited[node] = true;
            path[node] = true;

            for(int nbr : adj[node]){
                if(!visited[nbr]){
                    if(cycleFinder(nbr, visited, path)){
                        return true;
                    }
                }
                else if(path[nbr] == true){
                    return true;
                }
            }

            //leave node
            path[node] = false;
            return false;
        }

        bool containsCycle(){

          
            bool *visited =new bool[100];
            bool *path  = new bool[100];

            for(int i=0; i < 100; i++){
                visited[i] = false;
                path[i] = false;
            }

            return cycleFinder(0, visited, path);
          
        }
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(4,2);
    

    if(g.containsCycle()){
        cout<<"Yes Cycle is Present!!";
    }else{
        cout<<"No cycle present";
    }
    return 0;
}