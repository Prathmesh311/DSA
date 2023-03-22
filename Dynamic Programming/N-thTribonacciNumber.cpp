class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }

        if(n == 1 || n == 2){
            return 1;
        }

        int num1 = 0;
        int num2 = 1;
        int num3 = 1;

        while(n-3 >= 0){
            int temp = num1+num2+num3;
            num1 = num2;
            num2 = num3;
            num3 = temp;
            n--;
        }

        return num3;
        
    }
};
