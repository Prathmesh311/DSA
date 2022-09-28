#include<iostream>
using namespace std;

int partition(int *arr, int start, int end){

    int i = start-1;
    int j = start;

    for(int j = start; j < end; j++){   //actual mechanism
        if(arr[j] < arr[end]){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[end], arr[i+1]);

    return i+1;

}

void quickSort(int *arr, int start, int end){
    //Base case
    if( start >= end){
        return;
    }

    //Recursive case
    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}


int main(){
    int arr[100];
    int n;

    cin>>n;

    for(int i=0; i < n; i++){
        cin>>arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i=0; i < n; i++){
        cout<<arr[i];
    }
 
    return 0;
}