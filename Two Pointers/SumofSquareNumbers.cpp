class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = sqrt(c);

        while(left <= right){
            long long currSquare = (long long)(pow(left, 2) + pow(right, 2)) % 10000000000;

            if(currSquare == c){
                return true;
            }else if(currSquare < c){
                left++;
            }else{
                right--;
            }
        }

        return false;
    }
};
