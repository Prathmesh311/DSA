class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> preTri = {1};

        while(rowIndex > 0){
            vector<int> currTri;
            currTri.push_back(1);

            for(int i=1; i < preTri.size(); i++){
                currTri.push_back(preTri[i-1] + preTri[i]);
            }

            currTri.push_back(1);
            preTri = currTri;
            rowIndex--;
        }

        return preTri;
    }
};
