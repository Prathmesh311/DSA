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

            //Path compressions Optimisation
            return parent[i] =  findSet(parent[i], parent);
        }


        void unionSet(int i, int j, int *parent, int *rank){
            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            //Union By Rank Optimization 
            if(s1 != s2){
                if(rank[s1] < rank[s2]){
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                }
                else{
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }
        }

        bool containsCycle(){

            int *parent =new int[100];
            int *rank = new int[100];

            for(int i=0; i < 100; i++){
                parent[i] = -1;
                rank[i] = 1;
            }


            for(auto p : l){
                int s1 = findSet(p.first, parent);
                int s2 = findSet(p.second, parent);

                if(s1 != s2){
                    unionSet(s1, s2, parent, rank);
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
    //g.addEdge(3,0);
   
    

    if(g.containsCycle()){
        cout<<"Yes Cycle is Present!!";
    }else{
        cout<<"No cycle present";
    }
    return 0;
}