class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=0; i < s.size()/2; i++){
            string sub = s.substr(0, i+1);
            int j = i+1;

            int flag = 0;
            while(j < s.size()){
                string temp = s.substr(j, i+1);
                
                if(sub != temp){
                    flag = 1;
                    break;
                }
                j = j + i+1;
            }

            if(flag == 0){
                return true;
            }
        }

        return false;
    }
};
