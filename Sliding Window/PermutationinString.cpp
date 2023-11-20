class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> s1Map;

        if(s1.size() > s2.size()){
            return false;
        }

        for(int i=0; i < s1.size(); i++){
            s1Map[s1[i]] += 1;
        }

        int s1Size = s1.size();
        map<char, int> s2Map;

        for(int i=0; i <= s2.size() - s1Size; i++){
            s2Map.clear();
            s2Map = s1Map;
            int flag = 0;

            for(int j = i; j < i + s1Size; j++){
                if(s2Map.find(s2[j]) == s2Map.end()){
                    flag = 1;
                    break;
                }

                s2Map[s2[j]] -= 1;

                if(s2Map[s2[j]] < 0){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                return true;
            }
        }

        return false;
    }
};
