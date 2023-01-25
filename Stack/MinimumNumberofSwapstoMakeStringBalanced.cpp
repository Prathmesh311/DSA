class Solution {
public:
    int minSwaps(string s) {

        if(s.size() % 2 != 0){
            return -1;
        }

        stack<char> stack;

        for(int i=0; i < s.size(); i++){
            if(s[i] == '['){
                stack.push(s[i]);
            }else{
                if(!stack.empty() && stack.top() == '['){
                    stack.pop();
                }else{
                    stack.push(s[i]);
                }
            }
        }


        int opening = 0;
        int closing = 0;
        while(!stack.empty()){
            if(stack.top() == '['){
                opening++;
            }else{
                closing++;
            }
            stack.pop();
        }

        int ans = (opening+1)/2 + (closing+1)/2;
        return ans/2;
        
    }
};
