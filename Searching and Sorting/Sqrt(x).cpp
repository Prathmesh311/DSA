class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1){
            return x;
        }
        
        long square = x;

        long left = 0;
        long right = x;


        while(left < right){
            long mid = left + (right - left)/2;

            if(mid * mid > square){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return (int)left-1;
    }
};
