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

        bool cycleFinder(int node, bool *visited, int parent){

            visited[node] = true;

            for(int nbr : adj[node]){
                if(!visited[nbr]){
                    if(cycleFinder(nbr, visited, node)){
                        return true;
                    }
                }
                else if(nbr != parent && visited[nbr] == true){  //if nbr is not parent of curr node
                    return true;
                }
            }
           
            return false;
        }

        bool containsCycle(){

            bool *visited =new bool[100];

            for(int i=0; i < 100; i++){
                visited[i] = false;
            }


            for(auto p : adj){
                if(!visited[p.first]){
                    if(cycleFinder(p.first, visited, -1)){
                        return true;
                    }
                }
            }
          
        }
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    

    if(g.containsCycle()){
        cout<<"Yes Cycle is Present!!";
    }else{
        cout<<"No cycle present";
    }
    return 0;
}