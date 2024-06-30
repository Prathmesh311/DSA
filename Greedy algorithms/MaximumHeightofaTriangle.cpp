class Solution {
public:
    int helper(int red, int blue) {
        int height = 0;
        int level = 1;

        while(true){
            if(level % 2 == 0){
                if(blue >= level){
                    blue -= level;
                }else{
                    break;
                }
            }else{
                if(red >= level){
                    red -= level;
                }else{
                    break;
                }
            }
            
            level++;
        }
        
        return level-1;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red, blue), helper(blue, red));
    }
};
