class RLEIterator {
private:
    vector<vector<int>> sequence;
    int index = -1;

public:
    RLEIterator(vector<int>& encoding) {
        for(int i = 0; i < encoding.size(); i = i+2){
            int count = encoding[i];
            int num = encoding[i+1];

            sequence.push_back({count, num});
        }
    }
    
    int next(int n) {
        int lastElement = -1;
        
        while(n > 0 && sequence.size() > 0){
            if(n > sequence[0][0]){
                n -= sequence[0][0];
                sequence.erase(sequence.begin());
            }else{
                sequence[0][0] -= n;
                n = 0;
                lastElement = sequence[0][1];
            }
        }

        return lastElement;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
