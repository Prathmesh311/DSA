class Solution {
public:
    int mySqrt(int x) {
        long sRoot;

        long start = 0;
        long end = (long)x;

        while(start <= end){
            long mid = start +  (end - start) / 2;

            long midSquare = mid * mid;
            if(midSquare == (long)x){
                return mid;
            }
            else if(midSquare < (long)x){
                sRoot = mid;
                start = mid + 1;
            }
            else{
                end = mid-1;
            }
        }

        return (int)sRoot;
    }
};
