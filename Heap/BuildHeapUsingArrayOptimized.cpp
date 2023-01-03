#include<iostream>
using namespace std;

void heapify(int* arr, int i, int size){
    int left = i*2;
    int right = left+1;

    int minIndex = i;
    int last = size-1;

    if(left <= last && arr[left] < arr[i]){
        minIndex = left;
    }
    if(right <= last && arr[right] < arr[minIndex]){
        minIndex = right;
    }

    if(minIndex != i){
        swap(arr[minIndex], arr[i]);
        heapify(arr, minIndex, size);
    }
}

void buildHeap(int* arr, int size){
    
    for(int i= (size-1)/2; i >= 1; i--){
       heapify(arr, i, size);
    };
}


int main(){
    int arr[] = {-1, 2, 4, 1, 10, 9, 45};
    int size =sizeof(arr)/sizeof(int);
    cout<<size;

    buildHeap(arr, size);
    
    for(int i=0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}