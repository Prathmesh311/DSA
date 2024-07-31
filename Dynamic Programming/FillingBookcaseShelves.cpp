class Solution {
public:
    int fillShelf(vector<vector<int>>& books, vector<int>& dp, int index, int shelfWidth){
        if(index >= books.size()){
            return 0;
        }

        if(dp[index] != INT_MAX){
            return dp[index];
        }
        
        int currWidth = shelfWidth;
        int maxHeight = 0;
        
        for(int i = index; i < books.size(); i++){
            int width = books[i][0];
            int height = books[i][1];

            if(currWidth < width){
                break;
            }

            currWidth -= width;

            maxHeight = max(maxHeight, height);
            dp[index] = min(dp[index], fillShelf(books, dp, i+1, shelfWidth) + maxHeight);
        }

        return dp[index];
    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size()+1, INT_MAX);

        return fillShelf(books, dp, 0, shelfWidth);
    }
};
