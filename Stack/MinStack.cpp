class MinStack {
private:
    vector<int> stack;
    vector<int> minStack;  //maintain seperate stack for min elements
public:
    MinStack() {
        
    }
    
    void push(int val) {

        int currMin = val;

        if(minStack.size()){
            currMin = min(minStack[minStack.size() - 1], val);   //for every element in main stack push min element in minStack
        }
        
        stack.push_back(val);
        minStack.push_back(currMin);
    }
    
    void pop() {
        stack.pop_back();           
        minStack.pop_back();       //For every pop in main stack pop element from minStack
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return minStack[minStack.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
