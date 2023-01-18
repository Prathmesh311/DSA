class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stack;

        //Processing string 1
        for(int i=0 ; i < s.size(); i++){
            if(s[i] == '#'){
                if(stack.empty()){
                    continue;
                }
                stack.pop();
            }else{
                stack.push(s[i]);
            }
        }

        string str1 = "";
        while(!stack.empty()){
            str1 = stack.top() + str1;
            stack.pop();
        }

        //processing string 2
        for(int i=0 ; i < t.size(); i++){
            if(t[i] == '#'){
                if(stack.empty()){
                    continue;
                }
                stack.pop();
            }else{
                stack.push(t[i]);
            }
        }

        string str2 = "";
        while(!stack.empty()){
            str2 = stack.top() + str2;
            stack.pop();
        }

        if(str1 == str2){
            return true;
        }

        return false;
        
    }
};
