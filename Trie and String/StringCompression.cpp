class Solution {
public:
    int compress(vector<char>& chars) {
        int compressedLen = 0;
        int i = 1;
        int counter = 1;

        for(; i < chars.size(); i++){
            if(chars[i] == chars[i-1]){
                counter++;
            }
            else{
                chars[compressedLen++] = chars[i-1];
                string currCount = to_string(counter);

                if(counter > 1){
                    for(char c : currCount){
                        chars[compressedLen++] = c;
                    }
                }

                counter = 1;
            }
        }

        chars[compressedLen++] = chars[i-1];
        string currCount = to_string(counter);

        if(counter > 1){
            for(char c : currCount){
                chars[compressedLen++] = c;
            }
        }

        return compressedLen;
    }
};
