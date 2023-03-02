#define psi pair<int, string>
class myComparator{
    public:
        bool operator() (const psi &p1, const psi &p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        
        return p1.first > p2.first;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> map;

        for(int i=0; i < words.size(); i++){
            if(map.find(words[i]) == map.end()){
                map[words[i]] = 0;
            }
            map[words[i]]++;
        }


        priority_queue<psi,  vector<psi>, myComparator> pq;
        

        for(auto p : map){
            pq.push({p.second, p.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> ans;

        while(pq.size() > 0){
            ans.insert(ans.begin(), pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
