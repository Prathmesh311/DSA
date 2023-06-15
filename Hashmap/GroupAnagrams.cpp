class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupAnag;
        unordered_map<string, vector<string>> groups;

        for(string str : strs){

            string temp = str; 
            sort(temp.begin(), temp.end());

            groups[temp].push_back(str);
            
            //By using scii value
            /*int totalVal = 0;
            for(char c : str){
                totalVal += int(c) - int('a');
            }

            groups[totalVal].push_back(str);*/
        }
        
        for(auto pair: groups){
            groupAnag.push_back(pair.second);
        }

        return groupAnag;
    }
};
