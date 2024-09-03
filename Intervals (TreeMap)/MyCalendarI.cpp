class MyCalendar {
public:
    map<int, int> map;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = map.lower_bound(start);

        if((next != map.end() &&  next->first < end)){
            return false;
        }

        if(next != map.begin()){
            auto prev = std::prev(next);
            if(prev->second > start){
                return false;
            }
        }
        
        map[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
