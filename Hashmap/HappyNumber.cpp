class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> map;

        while(n != 1){

            if(map[n] == 0){    //placing number in hashmap
                map[n]++;
            }
            else{               //If number is comming repeting then return
                return false;
            }

            int newNumber = 0;

            while(n > 0){
                newNumber += pow(n % 10,2);;
                n = n/10;
            }

            n = newNumber;
        }
        
        return true;
    }
};
