#include<iostream>
#include <bits/stdc++.h>
using namespace std;


class Graph{

    public: 
        vector<pair<int, int>> *edges;
        int V;
        
        Graph(int V){
            this->V = V;
            edges = new vector<pair<int, int>>[V];
        }

        void addEdge(int x, int y, int w){
            edges[x].push_back({y, w});
            edges[y].push_back({x, w});
        }

        int primMST(){
           
           //Initiated a MIN HEAP
            priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> Q;
            bool *visited = new bool[V]{false};

            Q.push({0,0});
            visited[0] = false;



            int totalCost = 0;  //1st weight, 2nd node

            while(!Q.empty()){
                auto best = Q.top();
                Q.pop();

                int to = best.second;
                int weight = best.first;

                if(visited[to] == true){
                    continue;
                }

                totalCost += weight;
                visited[to] = true;

                for(auto edge : edges[to]){
                    if(visited[edge.first] == false){
                        Q.push({edge.second, edge.first});
                    }
                }
            }
           

            return totalCost;
        }

};

int main(){
    Graph g(4);

    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);

    cout<<g.primMST();

    return 0;
}