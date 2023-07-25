class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        int n = arr.size();

        while(start <= end){
            int mid = start + (end - start)/2;

            int currNum = arr[mid];

            if((mid-1 < 0  || currNum > arr[mid-1]) && (mid+1 > arr.size()-1  || currNum > arr[mid+1])){
                return mid;
            }
            if(mid-1 >= 0  && currNum < arr[mid-1]){
                end = mid-1;
            }
            else if(mid+1 < n && currNum < arr[mid+1]){
                start = mid+1;
            }
        }

        return -1;
    }
};
