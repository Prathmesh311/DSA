class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;

        int minWindow = INT_MAX;

        int counter = t.size();
        int start = 0;
        int head = 0;

        for(char c : t){
            map[c] += 1;
        }

        for(int end = 0; end < s.size(); end++){
            if(map[s[end]] > 0){
                counter--;
            }
            map[s[end]]--;

            while(counter == 0){
                if(end - start < minWindow){
                    minWindow = min(end - start, minWindow);
                    head = start;
                }

                map[s[start]]++; 
                if (map[s[start]] > 0) {
                    counter++;
                }
                start++;
            }
        }

        return minWindow == INT_MAX ? "" : s.substr(head, minWindow+1);
    }
};
