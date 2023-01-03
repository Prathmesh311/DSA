#include<iostream>
using namespace std;

void heapify(int* arr, int i, int size){
    int left = i*2;
    int right = left+1;

    int maxIndex = i;
    int last = size-1;

    if(left <= last && arr[left] > arr[i]){
        maxIndex = left;
    }
    if(right <= last && arr[right] > arr[maxIndex]){
        maxIndex = right;
    }

    if(maxIndex != i){
        swap(arr[maxIndex], arr[i]);
        heapify(arr, maxIndex, size);
    }
}

void buildHeap(int* arr, int size){
    
    for(int i= (size-1)/2; i >= 1; i--){
       heapify(arr, i, size);
    };
}

void heapSort(int* arr, int size){
    buildHeap(arr, size);
    int n = size;

    while(n > 1){
        swap(arr[1], arr[n-1]);
        n--;

        heapify(arr, 1, n);
    }
}


int main(){
    int arr[] = {-1, 2, 4, 1, 10, 9, 45};
    int size =sizeof(arr)/sizeof(int);

    heapSort(arr, size);
    
    for(int i=0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}