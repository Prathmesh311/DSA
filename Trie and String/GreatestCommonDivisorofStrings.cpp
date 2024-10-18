class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        int len = min(str1.size(), str2.size());


        while(len > 0){
            if(str1.size() % len == 0 && str2.size() % len == 0){
                string currStr = str2.substr(0, len);

                int newStr2Multiple = str2.size() / len;
                int newStr1Multiple = str1.size() / len;
                string newStr1 = "";
                string newStr2 = "";

                for(int i=0; i < newStr1Multiple; i++){
                    newStr1 += currStr;
                }

                for(int i=0; i < newStr2Multiple; i++){
                    newStr2 += currStr;
                }

                if(newStr1 == str1 && newStr2 == str2){
                    return currStr;
                }
            }
            len--;
        }
        return "";
    }
};
