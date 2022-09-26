#include <iostream>
using namespace std;


bool binarySearch( int arr[], int start, int end, int num){
    //base case
    if(start >= end){
        return false;
    }


    //recursive case

    int mid  = (end - start + 1) /2;

     if(arr[mid] == num){
        cout<<"found";
        return true;
    }

    if(arr[mid] > num){
      return  binarySearch(arr, start, mid - 1, num);
    }

    
    if(arr[mid] < num){
       return  binarySearch(arr, mid + 1, end, num);
    }


    return false;


};

int main() {
    int arr[] = {1,3,4, 8, 10};
    
   
    cout<<binarySearch(arr, 0, 4, 3);
    return 0;
}