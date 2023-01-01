#include<iostream>
using namespace std;

void buildHeap(int* arr, int size){
    
    for(int i=2; i < size; i++){
        int index = i;
        int parent = i/2;

        while(index > 1 && arr[index] > arr[parent]){
            swap(arr[index], arr[parent]);
            index = parent;
            parent = parent/2;
        }
    };
}


int main(){
    int arr[] = {-1, 2, 4, 1, 10, 9, 45};
    int size =sizeof(arr)/sizeof(int);

    buildHeap(arr, size);
    
    for(int i=0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}