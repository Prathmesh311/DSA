class Solution {
public:
    bool isSubsequence(string s, string t) {
      
        //If s empty it's subseqeunce automatically 
        if(s.length() == 0){
            return true;
        }
        
        //using 2 pointers checking sunsequence
        int i=0, j=0;
        while(i < s.length() && j < t.length()){
            if(s[i] == t[j]){
                i++;
                j++;
                
                //if s found return true 
                if(i == s.length()){
                    return true;
                }
            }
            else{
                j++;
            }
            
        }
        
        return false;
    }
};
