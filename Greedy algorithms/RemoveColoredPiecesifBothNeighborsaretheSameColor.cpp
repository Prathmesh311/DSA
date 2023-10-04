class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;

        for(int i=1; i < colors.size(); i++){
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A'){
                alice++;
            }
            else if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B'){
                bob++;
            }
        }


        if(alice <= bob){
            return false;
        }
        return true;
        
    }
};
