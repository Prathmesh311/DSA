class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> wordsSentence1;
        vector<string> wordsSentence2;


        stringstream ss1(sentence1);
        string word;
        while (ss1 >> word) {
            wordsSentence1.push_back(word);
        }

        stringstream ss2(sentence2);
        while (ss2 >> word) {
            wordsSentence2.push_back(word);
        }

        int p1 = 0; 
        int p2 = 0;
        while(p1 < wordsSentence1.size() && p2 < wordsSentence2.size() && wordsSentence1[p1] == wordsSentence2[p2]){
            p1++;
            p2++;
        }

        int end1 = wordsSentence1.size()-1;
        int end2 = wordsSentence2.size()-1;

        while(end1 >= 0 && end2 >= 0 && wordsSentence1[end1] == wordsSentence2[end2]){
            end1--;
            end2--;
        }        

        return p1 > end1 || p2 > end2;
    }
};
