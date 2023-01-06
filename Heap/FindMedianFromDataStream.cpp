class MedianFinder {
public:
    priority_queue<int> leftHeap;     //MaxHeap that contains elements smaller than median
    priority_queue<int, vector<int>, greater<int>> rightHeap;   //MinHeap  that contains elements greater than median

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftHeap.size() == 0 && rightHeap.size() == 0){  //1st element should be put in leftHeap
            leftHeap.push(num);
            return;
        }
      
        if(leftHeap.size() > rightHeap.size()){            //balancing 2 heaps and putting element in aproriate location
            if(num < findMedian()){
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
            }
            else{
                rightHeap.push(num);
            }
        }
        else if(leftHeap.size() < rightHeap.size()){
            if(num > findMedian()){
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
            }
            else{
                leftHeap.push(num);
            }
        }
        else if(leftHeap.size() == rightHeap.size()){
            if(num > findMedian()){
                rightHeap.push(num);
            }
            else{
                leftHeap.push(num);
            }
        }
        
    }
    
    double findMedian() {
       if(leftHeap.size() > rightHeap.size()){
           return leftHeap.top();
       }
       if(leftHeap.size() < rightHeap.size()){
           return rightHeap.top();
       }

       return (leftHeap.top() + rightHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
