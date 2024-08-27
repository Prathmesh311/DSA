class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string> result;
        int prevSize = 0;

        for(string str : dictionary){
            int j = 0;

            for(int i = 0; i < s.size(); i++){
                if(s[i] == str[j]){
                    j++;

                    if(j >= str.size()){
                        if(!result.empty() && str.size() > result[0].size()){
                            result.clear();
                            result.push_back(str);
                            prevSize = str.size();
                        }else if(str.size() >= prevSize){
                            result.push_back(str);
                            prevSize = str.size();
                        }
                        break;
                    }
                }
            }
        }

        sort(result.begin(), result.end());

        return result.empty() ? "" : result[0];
    }
};
