class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map;

        for(int i=0; i < s.size(); i++){
            if(map.find(s[i]) == map.end()){
                map.insert(make_pair(s[i], 1));
            }else{
                map[s[i]] += 1;
            }
        }

        for(int i=0; i < t.size(); i++){
            if(map.find(t[i]) == map.end()){
                map.insert(make_pair(t[i], 1));
            }else{
                map[t[i]] -= 1;
            }
        }

        for(pair pair: map){
            if(pair.second != 0){
                return false;
            }
        }

        return true;
    }
};