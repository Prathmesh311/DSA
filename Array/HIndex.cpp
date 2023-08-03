class Solution {
public:
    int hIndex(vector<int>& citations) {
        int indexH  = -1;
        sort(citations.begin(), citations.end());

        for(int i=0; i < citations.size(); i++){
            if(citations[i] <= citations.size() - i){
                indexH = citations[i];
            }
            else if(citations[i] > citations.size() - i){
                int diff = citations.size() - i;
                indexH = max(indexH, diff);
            }
        }

        return indexH;
    }
};
