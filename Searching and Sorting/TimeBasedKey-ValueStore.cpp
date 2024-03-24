class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(map.find(key) == map.end()){
            return "";
        }

        int start = 0;
        int end = map[key].size()-1;

        while(start <= end){
            int mid = (start + end) / 2;

            if(map[key][mid].first == timestamp){
                return map[key][mid].second;
            }
            else if(map[key][mid].first < timestamp){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }

        if(end >= 0){
            return map[key][end].second;
        }

        return "";
    }
};
