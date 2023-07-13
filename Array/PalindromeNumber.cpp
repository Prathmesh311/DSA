class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        long oldNum = (long)x;
        long num =  x % 10;
        x = x / 10;

        while(x > 0){
            int rem = x % 10;
            x = x / 10;

            num = num * 10 + rem;
        }

        if(num == oldNum){
            return true;
        }

        return false;
    }
};
