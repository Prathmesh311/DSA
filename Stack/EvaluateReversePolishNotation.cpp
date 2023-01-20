#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for(int i=0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();

                if(tokens[i] == "+"){
                    int sum = num1 + num2;
                    stack.push(sum);
                }
                else if(tokens[i] == "-"){
                    int sub = num2 - num1;
                    stack.push(sub);
                }
                else if(tokens[i] == "/"){
                    int div = num2 / num1;
                    stack.push(div);
                }
                else if(tokens[i] == "*"){
                    int mul = num1 * num2;
                    stack.push(mul);
                }
            }
            else{
                stringstream sso(tokens[i]);
                int k;
                sso>>k;
                stack.push(k);
            }
        }
        return stack.top();
    }
};
