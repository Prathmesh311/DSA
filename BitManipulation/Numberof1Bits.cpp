class Solution {
public:
    //Method 1: 
    int countSetBits(uint32_t n){
        int ans = 0;

        while(n > 0){
            ans += n & 1;
            n = n>>1;
        }
        return ans;
    }

    //Method 2:
    int countSetBitsFast(uint32_t n){
        int ans = 0;

        while(n > 0){
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
  
    int hammingWeight(uint32_t n) {
       //return countSetBits(n);
       return countSetBitsFast(n);
    }
};
