class Solution {
public:
    //Method 1: using Map and Set
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

    //Method 2: using 2 Maps
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;

         for (int i = 0; i < s.size(); ++i) {
            if (sMap.find(s[i]) == sMap.end() && tMap.find(t[i]) == tMap.end()) {
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            } else {
                if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};
