class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapT;
        unordered_map<char, int> mapS;
        int minLen = INT_MAX;

        for(char c : t){
            mapT[c]++;
        }

        int left = 0;
        int start = 0;
        int end = INT_MAX;

        int have = 0;
        int need = mapT.size();

        for(int right=0; right < s.size(); right++){
            char c = s[right];

            if(mapT.find(c) != mapT.end()){
                mapS[c]++;
                if(mapS[c] == mapT[c]){
                    have++;
                }
            }
           
            while(have == need && left <= right){
                if(right - left + 1 < minLen){
                    minLen = min(minLen, right-left+1);
                    start = left;
                    end = right+1;
                }
                
                if(mapT.find(s[left]) != mapT.end()){
                    mapS[s[left]]--;
                    if(mapS[s[left]] < mapT[s[left]]){
                        have--;
                    }
                }
                left++;
            }
        }
        
        return end - start < INT_MAX ? s.substr(start, end-start) : "";
    }
};
