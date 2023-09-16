class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
  
    }
    
    int ping(int t) {
        q.push(t);
        int recentElement = q.back();
       
        while(recentElement - q.front() > 3000){
            q.pop();
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
