class MyQueue {
public:
    stack<int> stack;
    std::stack<int> helperStack;

    MyQueue() {
        
    }
    
    void push(int x) {
        stack.push(x);
    }
    
    int pop() {
        while(!stack.empty()){
            int num = stack.top();
            stack.pop();
            helperStack.push(num);
        }

        int removedElement = helperStack.top();
        helperStack.pop();

        while(!helperStack.empty()){
            int num = helperStack.top();
            helperStack.pop();
            stack.push(num);
        }
        return removedElement;
    }
    
    int peek() {
        while(!stack.empty()){
            int num = stack.top();
            stack.pop();
            helperStack.push(num);
        }

        int topElement = helperStack.top();

        while(!helperStack.empty()){
            int num = helperStack.top();
            helperStack.pop();
            stack.push(num);
        }
        return topElement;
    }
    
    bool empty() {
        if(stack.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
