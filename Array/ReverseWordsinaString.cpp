class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string reversedString = "";

        stringstream ss(s);
        string word;

        while(getline(ss, word, ' ')){
            words.push_back(word);
        }

        for(int i=words.size()-1; i >= 0; i--){
            if(words[i] == ""){
                continue;
            }
            reversedString += words[i] + " ";
        }

        return reversedString.substr(0, reversedString.size()-1);
    }
};
