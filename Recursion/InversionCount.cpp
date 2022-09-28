#include<iostream>
using namespace std;


int merge(int *arr, int start, int end){
    int temp[100];
    int mid = (start + end) /2;
    int i = start;
    int j = mid+1;
    int k = start;

    int crossInversions = 0;    //inversion counter

    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            crossInversions += mid - i + 1;  //remaining elements in 1st array will make cross inversions with arr[j]
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }

    for(int i=start; i <= end; i++){
        arr[i] = temp[i];
    }

    return crossInversions;
}

int inversionCount(int *arr, int start, int end){
    //Base case
    if(start >= end){
        return 0;
    }

    //Recursive case
    int mid = (start + end)/2;

    int x = inversionCount(arr, start, mid);
    int y = inversionCount(arr, mid+1, end);

    int z = merge(arr, start, end); //cross inversions


    return x + y + z;
}

int main(){
    int arr[100];
    int n;

    cin>>n;

    for(int i=0; i < n; i++){
        cin>>arr[i];
    }

    cout<<"Inversion Count: "<<inversionCount(arr, 0, n-1);
    return 0;
}