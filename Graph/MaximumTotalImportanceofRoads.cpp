class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long> roadImp(n);

        for(auto v : roads){
            roadImp[v[0]]++;
            roadImp[v[1]]++;
        }

        sort(roadImp.begin(), roadImp.end(), greater<long>());

        long long maxRoadImp = 0;
        long counter = n;

        for(long Imp : roadImp){
            maxRoadImp += counter * Imp;
            counter--;
        }

        return maxRoadImp;
    }
};
