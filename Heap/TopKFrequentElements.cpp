#define psi pair<int, int>
class myComparator{
    public:
        bool operator() (const psi &p1, const psi &p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        
        return p1.first > p2.first;
        }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> map;

        for(int i=0; i < nums.size(); i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 0;
            }
            map[nums[i]]++;
        }

        priority_queue<psi,  vector<psi>, myComparator> pq;

        for(auto p : map){
            pq.push({p.second, p.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(pq.size() > 0){
            ans.insert(ans.begin(), pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
