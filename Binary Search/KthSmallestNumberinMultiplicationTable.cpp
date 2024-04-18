class Solution {
public:
    bool isFeasible(int m, int n, int k, int value){
        int smallerElements = 0;

        for(int i=1; i <= m; i++){
            smallerElements += value > i * n ? n : value / i;
        }

        if(smallerElements >= k){
            return true;
        }

        return false;
    }


    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;

        while(left < right){
            int mid = left + (right - left)/2;

            if(isFeasible(m, n, k, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};
