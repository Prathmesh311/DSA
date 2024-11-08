class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;

        stringstream ss(path);
        string temp;

        while(getline(ss, temp, '/')){
            if(temp == ".."){
                if(!stack.empty()){
                    stack.pop();
                }
            }else if(temp != "." && temp != ""){
                stack.push(temp);
            }
        }


        string simplePath = "";
        while(!stack.empty()){
            simplePath = "/" + stack.top() + simplePath; 
            stack.pop();
        }

        return simplePath.empty() ? "/" : simplePath;
    }
};
