class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nIndex = 0;
        int tIndex = 0;

        while(nIndex < name.size()){
            if(tIndex >= typed.size()){
                return false;
            }

            if(name[nIndex] != typed[tIndex]){
                if(nIndex > 0 && name[nIndex-1] == typed[tIndex]){
                    tIndex++;
                }else{
                    return false;
                }
            }else{
                nIndex++;
                tIndex++;
            }
        }

        while(tIndex < typed.size()){
            if(nIndex > 0 && name[nIndex-1] == typed[tIndex]){
                    tIndex++;
            }else{
                return false;
            }
        }

        return true;
        
    }
};
