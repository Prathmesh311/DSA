class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26] = {0};
        int cost = 0;

        for(char c : s){
            arr[c - 'a']++; 
        }

        for(char c : t){
            arr[c - 'a']--; 
        }

        for(int i=0; i < 26; i++){
            if(arr[i] > 0){
                cost += arr[i];
            }
        }
        
        return cost;
    }
};
