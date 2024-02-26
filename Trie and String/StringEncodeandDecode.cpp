
class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";

        //encode string with (len of word + #)
        for(string word : strs){
            encodedString += to_string(word.size()) + "#" + word;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> result;
        
        
        while (!s.empty()) {
            int index = 0;
            while (s[index] != '#') {     //find index of #
                index++;
            }

            int length = stoi(s.substr(0, index));  //find len of string

            string str = s.substr(index + 1, length); //find curr string
            result.push_back(str);

            s = s.substr(index + 1 + length);   //update encoded string to remove decoded string
        }
        
        return result;
    }
};
