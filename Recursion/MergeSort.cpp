#include <iostream>
using namespace std;



void merge(int *arr, int start, int end){
    int temp[100];
    int mid = (start+end)/2;

    int i = start;
    int j = mid+1;
    int k = start;


    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    //copy remaining elements in 2 arrays
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while( j <= end){
        temp[k++] = arr[j++];
    }

    //coping all elements from temp[] to arr[]
    for(int i=start; i <= end; i++){
        arr[i] = temp[i];
    }
}


void MergeSort(int *arr, int start, int end){
    //Base case
    if(start >= end){
        return;
    }

    //recursive case
    int mid = (start + end)/2;

    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);

    merge(arr, start, end);
  
}


int main() {
    int arr[100];
    int n;

    cin>>n;
    for(int i=0; i < n; i++){
        cin>>arr[i];
    }
    
    MergeSort(arr, 0, n-1);

    for(int i=0; i < n; i++){
        cout<<arr[i]<<", ";
    }
   
    return 0;
}