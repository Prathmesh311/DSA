class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        unordered_map<char, int> temp;

        int counter = s1.size();
        int start = 0;
        int end = 0;

        for(char c : s1){
            map[c] += 1;
            temp[c] += 1;
        }

        while(end < s2.size()){
            if(temp.find(s2[end]) != temp.end()){
                if(temp[s2[end]] > 0){
                    counter--;
                    temp[s2[end]]--;

                    if(counter == 0){
                        return true;
                    }
                    end++;
                }else{

                    while(temp[s2[end]] <= 0 && start < end){
                        temp[s2[start]]++;
                        counter++;
                        start++;
                    }
                }
            }
            else{
                counter = s1.size();
                temp = map;
                end++;
                start = end;
            }
        }   

        return false;
    }


    //Method 2:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        
        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);
        
        // Initialize the character counts for s1 and the first window of s2
        for (int i = 0; i < s1.length(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }

        int count = 0;
        // Count the number of matches in character frequency
        for (int i = 0; i < 26; i++) {
            if (s1map[i] == s2map[i]) {
                count++;
            }
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            int r = s2[i + s1.length()] - 'a';
            int l = s2[i] - 'a';
            
            if (count == 26) {
                return true;
            }
            
            s2map[r]++;
            if (s2map[r] == s1map[r]) {
                count++;
            } else if (s2map[r] == s1map[r] + 1) {
                count--;
            }
            
            s2map[l]--;
            if (s2map[l] == s1map[l]) {
                count++;
            } else if (s2map[l] == s1map[l] - 1) {
                count--;
            }
        }
        
        return count == 26;
    }

};
