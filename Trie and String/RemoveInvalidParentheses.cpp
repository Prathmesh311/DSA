class Solution {
public:
    void traverse(string &s, map<int, set<string>> &map, int index, string currStr, int stack){
        if(index >= s.size()){
            if(stack == 0){
                map[currStr.size()].insert(currStr); 
            }
            return;
        }
        

        if((s[index] != '(' && s[index] != ')')){
            return traverse(s, map, index+1, currStr + s[index], stack);
        }

        if((stack == 0 && s[index] == ')')){
            return traverse(s, map, index+1, currStr, stack);
        }
        
        traverse(s, map, index+1, currStr, stack);
        traverse(s, map, index+1, currStr + s[index], s[index] == '(' ? stack+1 : stack-1);
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        map<int, set<string>> map;

        traverse(s, map, 0,  "", 0); 
      
        auto it = map.rbegin();
        
        if(it != map.rend()){
            set<string> set = it->second; 
            ans.assign(set.begin(), set.end()); 
        } else {
            ans.push_back(""); 
        }

        return ans;
    }
};
