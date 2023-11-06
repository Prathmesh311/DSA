class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    vector<int> seats;

    SeatManager(int n) {
        for(int i=1; i <= n; i++){
            heap.push(i);
            seats.push_back(0);
        }
    }
    
    int reserve() {
        int availableSeat = heap.top();
        heap.pop();
        seats[availableSeat-1] = 1;
        return availableSeat;
    }
    
    void unreserve(int seatNumber) {
        seats[seatNumber-1] = 0;
        heap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
