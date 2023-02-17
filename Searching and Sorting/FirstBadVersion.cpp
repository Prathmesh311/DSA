// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;

        while(start <= end){
            int mid = start + (end - start)/2;

            bool curr = isBadVersion(mid);
            bool prev = isBadVersion(mid-1);
           
            if(curr == 1 && prev == 0 && mid-1 > 0){
                return mid;
            }
            else if(curr == false){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        return 1;
    }
};