
#include<iostream>
#include<vector>
using namespace std;



class Heap{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b){
        if(minHeap){
            return a<b;
        }
        return a>b;
    }

public:
    Heap(int defaultSize = 10, bool type = true){
        v.reserve(defaultSize);
        v.push_back(-1);
        minHeap = type;
    }


    void insert(int num){
        v.push_back(num);
        int index = v.size()-1;
        int parent = index/2;

        while(index > 1 && compare(v[index], v[parent])){
            swap(v[index], v[parent]);
            index = parent;
            parent = parent/2;
        }
    }

    void printHeap(){
        for(int i=1; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
    }
};


int main(){
    Heap heap;

    int arr[] ={3, 5, 1, 8, 10};

    for(int i=0; i <5; i++){
        heap.insert(arr[i]);
    }

    heap.printHeap();
    return 0;
}