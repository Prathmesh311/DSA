class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){    //untill carry not equal to 0
            int temp = (a & b) << 1;    //calculates carry at each position and shift to left by 1
            a = (a ^ b);       //xor at each location
            b = temp;
        }

        return a;   
    }
};
