class Solution {
public:

    bool isPalindrome(string subset){
        int start = 0;
        int end = subset.size()-1;

        while(start <= end){
            if(subset[start] != subset[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void traverse(string s, vector<vector<string>> &palindromes, vector<string> partitions, string subset, int index){
        if(index == s.size()){
            palindromes.push_back(partitions);
            return;
        }

        for(int i = index; i < s.size(); i++){
            subset += s[i]; // Append the character to the subset
            if(isPalindrome(subset)){
                partitions.push_back(subset);
                traverse(s, palindromes, partitions, "", i+1);
                partitions.pop_back();
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromes;
        vector<string> partitions;
        string subset = "";

        traverse(s, palindromes, partitions, subset, 0);

        return palindromes;
    }
};
