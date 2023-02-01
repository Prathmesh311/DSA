#include<iostream>
#include<vector>
using namespace std;

int uniqueNumber(vector<int>& arr) {
        int ans = 0;

        for(int i=0; i < arr.size(); i++){
            ans = ans^arr[i];               //Bitwise XOR operator used (This makes XOR of similar number = 0)
        }
        if(ans == 0){
            return -1;
        }
        return ans;
}
int main(){
    vector<int> arr{1,2,2,3,1};

    cout<<"Unique Number: "<<uniqueNumber(arr);

    return 0;
}