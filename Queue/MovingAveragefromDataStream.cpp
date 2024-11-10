class MovingAverage {
public:
    deque<int> q;
    int size;
    double sum;

    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        q.push_back(val);
        sum += (double)val;

        if(q.size() > size){
            int frontVal = q.front();
            q.pop_front();
            sum -= (double)frontVal;
        }

        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
