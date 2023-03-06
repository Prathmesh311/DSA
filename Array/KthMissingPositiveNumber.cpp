class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int index = 0;

        for(int i=1; i <= 10000; i++){

            if(k == 0){
                return i-1;
            }
           
            if(index < arr.size() && i == arr[index]){
                index++;
                continue;
            }

            k--;

        }

        return -1;
        
    }
};
