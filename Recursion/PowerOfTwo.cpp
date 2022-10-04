class Solution {
public:
    bool isPowerOfTwo(int n) {
        //Base case
        if(n == 1){
            return true;
        }
        
        if(n % 2 != 0 || n == 0){
            return false;
        }
        
        
        //Recursive case
        return isPowerOfTwo(n/2);
        
    }
};
