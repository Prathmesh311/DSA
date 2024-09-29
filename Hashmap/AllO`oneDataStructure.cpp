class AllOne {
public:
    set<pair<int, string>> freq;
    unordered_map<string, int> location;

    AllOne() {
        
    }
    
    void inc(string key) {
        int n = location[key];
        location[key] += 1;
        freq.erase({n, key});
        freq.insert({n+1, key});
    }
    
    void dec(string key) {
        int n = location[key];
        location[key] -= 1;
        freq.erase({n, key});

        if(location[key] == 0){
            location.erase(key);
            return;
        }
        freq.insert({n-1, key});
    }
    
    string getMaxKey() {
        if(!freq.empty()){
            return freq.rbegin()->second;
        }

        return "";
    }
    
    string getMinKey() {
        if(!freq.empty()){
            return freq.begin()->second;
        }

        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
