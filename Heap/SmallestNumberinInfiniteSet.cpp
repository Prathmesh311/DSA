class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> set;

    SmallestInfiniteSet() {
        for(int i=1; i <= 1000; i++){
            pq.push(i);
            set.insert(i);
        }
    }
    
    int popSmallest() {
        int smallest = pq.top();
        pq.pop();
        set.erase(smallest);

        return smallest;
    }
    
    void addBack(int num) {
        if(set.find(num) == set.end()){
            set.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
