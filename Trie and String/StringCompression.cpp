class Solution {
public:
    int compress(vector<char>& chars) {
        int totalLen = 0;
        vector<char> compress;


        for(int i=0; i < chars.size(); i++){   //Interating over array of string
            int currLen = 0;
            char currChar = chars[i];

            for(int j = i; j < chars.size(); j++){
                if(chars[j] == currChar){      // count consecutive occurances of specific char 
                    currLen++;
                }
                else{
                    break;
                }
            }
          
            compress.push_back(currChar);     //push char in new string
            
            if(currLen == 1){
                continue;
            }
            
            i = i + currLen-1;
            stack<int> stack;
            while(currLen > 0){               //splitting number of occurances in single char 
                int rem = currLen % 10;
                currLen  = currLen / 10;

                stack.push(rem);
            }

            while(!stack.empty()){            //pushing occurances single chars to new string
                int num = stack.top();
                stack.pop();
                char c = num + '0';
                compress.push_back(c);
            }

        }
      
        chars = compress;                     //assiging new string 
        return chars.size();                  //returning new string size
        
    }
};
