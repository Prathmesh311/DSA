/*

exppresion = "3-2*5/7+2"
o/p = 4
   4
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int index = 0;
        char prevSign = '+';  // Initialize prevSign to '+'

        while (index < s.size()) {
            if (isdigit(s[index])) {
                int currNum = 0;
                while (index < s.size() && isdigit(s[index])) {
                    currNum = currNum * 10 + (s[index] - '0');
                    index++;
                }

                // Apply the previous sign to the current number
                if (prevSign == '+') {
                    stack.push(currNum);
                } else if (prevSign == '-') {
                    stack.push(-currNum);
                } else if (prevSign == '*') {
                    int num = stack.top();
                    stack.pop();
                    stack.push(num * currNum);
                } else if (prevSign == '/') {
                    int num = stack.top();
                    stack.pop();
                    stack.push(num / currNum);
                }
            } else if (s[index] != ' ') {
                prevSign = s[index];
                index++;
            } else {
                index++;  // Skip spaces
            }
        }

        int ans = 0;
        while (!stack.empty()) {
            ans += stack.top();
            stack.pop();
        }

        return ans;
    }
};
