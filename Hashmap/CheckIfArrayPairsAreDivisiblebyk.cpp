class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainders;
        int pairsFormed = 0;

        for(int i=0; i < arr.size(); i++){
            int currRem = arr[i] % k;
            
            if(currRem < 0){
                currRem += k;
            }
            remainders[currRem] += 1;
        }

        if(remainders[0] %2 != 0){
            return false;
        }

        for(int i=1; i <= k/2; i++){
            if(remainders[i] != remainders[k - i]){
                return false;
            }
        }
        return true;
    }
};
