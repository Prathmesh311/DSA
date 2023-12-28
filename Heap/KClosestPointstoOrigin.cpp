class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> ans;


        for(int i=0; i < points.size(); i++){
            int square = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push({square, i});
        }

        while(k > 0){
            pair<int, int> p = pq.top();
            pq.pop();

            ans.push_back(points[p.second]);
            k--;
        }

        return ans;
    }
};
