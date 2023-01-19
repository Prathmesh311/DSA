class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for(int i=0; i < s.size(); i++){
            if(s[i] == ')' && !stack.empty()){
                char currBracket = stack.top();
                stack.pop();
                if(currBracket != '('){
                    return false;
                }
            }
            else if(s[i] == ']' && !stack.empty()){
                char currBracket = stack.top();
                stack.pop();
                if(currBracket != '['){
                    return false;
                }
            }
            else if(s[i] == '}' && !stack.empty()){
                char currBracket = stack.top();
                stack.pop();
                if(currBracket != '{'){
                    return false;
                }
            }else{
                stack.push(s[i]);
            }
        }

        if(stack.size() == 0){
            return true;
        }

        return false;
        
    }
};
