class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        set<char> set;

        for(int i=0; i < s.size(); i++){
            auto it = set.find(t[i]);

            if(map.find(s[i]) == map.end() && it == set.end()){
                map.insert(make_pair(s[i], t[i]));              //store char associated with characters
                set.insert(t[i]);                               //store char taken 
            }else{
                if(map[s[i]] != t[i]){
                    return false;
                }
            }
        }

        return true;
    }
};
