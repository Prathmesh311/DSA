#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    
    list<pair<int, int>> l;
    public:
        void addEdge(int x, int y){
            l.push_back(make_pair(x, y));
        }

        int findSet(int i, int parent[]){
            if(parent[i] == -1){
                return i;
            }

            return findSet(parent[i], parent);
        }


        void unionSet(int i, int j, int parent[]){
            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1 != s2){
                parent[s2] = s1;
            }
        }

        bool containsCycle(){

            int *parent =new int[100];

            for(int i=0; i < 100; i++){
                parent[i] = -1;
            }


            for(auto p : l){
                int s1 = findSet(p.first, parent);
                int s2 = findSet(p.second, parent);

                if(s1 != s2){
                    unionSet(s1, s2, parent);
                }
                else
                {
                    return true;
                }
                
            }

            return false;
          
        }
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
   
    

    if(g.containsCycle()){
        cout<<"Yes Cycle is Present!!";
    }else{
        cout<<"No cycle present";
    }
    return 0;
}