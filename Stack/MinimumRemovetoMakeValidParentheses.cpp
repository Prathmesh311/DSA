class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> open;
      
        for(int i=0; i < s.size(); i++){
            if(s[i] == '('){                        //keeping track of open brackets
                open.push(s[i]);
            }
            if(s[i] == ')' && open.size() == 0){    //Remove closing bracket if sufficient opening breackets are not present
                s = s.substr(0, i) + s.substr(i+1);
                i--;
            }
            else if(s[i] == ')'){                   //remove opening breacket from stack to keep track of extra opening brackets
                open.pop();
            }
        }

        int index = s.size() - 1;
        while(open.size() != 0 && index >= 0){      //removes extra opening breacket from the strint
            if(s[index] == '('){
                s = s.substr(0, index) + s.substr(index+1);
                open.pop();
                index++;
            }
            index--;
        }

        return s;
    }
};
