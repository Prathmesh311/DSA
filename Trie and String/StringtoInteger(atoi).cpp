class Solution {
public:
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }

    int myAtoi(string s) {
        int number = 0;
        int index = 0;

        while(index < s.size() && s[index] == ' '){
            index++;
        }

        bool negative = false;
        if(s[index] == '-' || s[index] == '+'){
            if(s[index] == '-'){
                negative = true;
            }
            index++;
        }

        int positiveMax = 2147483647;
        int negativeMin = 2147483648;
    
        bool leadingZeros = true;
        while(index < s.size() && isDigit(s[index])){
            int digit = s[index] - '0';

            if(leadingZeros && digit == 0){
                index++;
                continue;
            }
            leadingZeros = false;


            if(number > (positiveMax - digit) / 10){
                return negative ? negativeMin : positiveMax;
            }

            number = number * 10 + digit;
            index++;
        }

        return negative ? -number : number;
    }
};
