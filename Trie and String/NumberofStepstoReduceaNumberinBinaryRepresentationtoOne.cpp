class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        while(s.size() != 1 || s[0] == '0'){
            //if last bit is 0 then it's even:- we can reduce the length of array to devide by 2
            if(s[s.size()-1] == '0'){            
                s = s.substr(0, s.size()-1);
            }else{
                //add 1 for odd numbers
                int carry = 1;
                for(int i = s.size()-1; i >=0 ; i--){
                    if(s[i] == '1'){
                        s[i] = '0';
                    }else{
                        s[i] = '1';
                        carry = 0;
                        break;
                    }
                }
                if(carry == 1){
                    s = '1' + s;
                }
            }
            steps++;
        }

        return steps;
    }
};
