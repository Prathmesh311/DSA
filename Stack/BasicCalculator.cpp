class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int currNum = 0;
        int result = 0;
        int sign = 1; // 1 represents '+', -1 represents '-'

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * currNum;
                sign = 1;
                currNum = 0;
            } else if (ch == '-') {
                result += sign * currNum;
                sign = -1;
                currNum = 0;
            } else if (ch == '(') {
                stack.push(result);
                stack.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * currNum;
                currNum = 0;
                result *= stack.top(); stack.pop(); // this is the sign before the parenthesis
                result += stack.top(); stack.pop(); // this is the result calculated before the parenthesis
            }
        }

        result += sign * currNum; // Add the last number, if any
        return result;
    }
};
