class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        vector<int> preTri = {1};
        ans.push_back(preTri);
       

        while(numRows - 1 > 0){
            vector<int> currTri;
            currTri.push_back(1);

            for(int i=1; i < preTri.size(); i++){
                currTri.push_back(preTri[i-1] + preTri[i]);
            }
            currTri.push_back(1);
            
            ans.push_back(currTri);
            preTri = currTri;
            numRows--;
        }

        return ans;
        
    }
};
