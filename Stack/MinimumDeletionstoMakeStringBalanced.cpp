class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> a(s.size(), 0);
        vector<int> b(s.size(), 0);
        
        int minDeletions = INT_MAX;
        int count = 0;


        for(int i=0; i < s.size(); i++){
            b[i] = count;
            if(s[i] == 'b'){
                count++;
            }
        }

        count = 0;
        for(int i=s.size()-1; i >= 0; i--){
            a[i] = count;
            if(s[i] == 'a'){
                count++;
            }
        }

        for(int i = 0; i < s.size(); i++){
            minDeletions = min(minDeletions, a[i] + b[i]); 
        }

        return minDeletions;
        
    }
};
