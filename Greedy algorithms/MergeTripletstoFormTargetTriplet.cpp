class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int> set;

        for(int i=0; i < triplets.size(); i++){
            //if any position of triplet is higher than target ignore that triplet
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                continue;
            }
            
            //if triplet value at specific index equal to target, add that index to set
            for(int j = 0; j < 3; j++){
                if(triplets[i][j] == target[j]){
                    set.insert(j);
                }
            }
        }

        //check if all 3 indexes we can generate through triplets
        return set.size() == 3;
    }
};
