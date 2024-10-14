class DinnerPlates {
private:
    set<int> availableStacks;          
    vector<stack<int>> stacks;       
    int capacity;                   

public:
    DinnerPlates(int cap){
        capacity = cap;
    }

    void push(int val) {
        if (availableStacks.empty()) {
            stacks.push_back(stack<int>());
            availableStacks.insert(stacks.size() - 1);
        }

        auto idx = *availableStacks.begin();
        stacks[idx].push(val);

        if (stacks[idx].size() == capacity) {
            availableStacks.erase(availableStacks.begin());
        }
    }

    int pop() {
        if (stacks.empty()) return -1;

        int result = stacks.back().top();
        stacks.back().pop();

        while (!stacks.empty() && stacks.back().empty()) {
            availableStacks.erase(stacks.size() - 1);
            stacks.pop_back();
        }

        if (!stacks.empty() && stacks.back().size() < capacity) {
            availableStacks.insert(stacks.size() - 1);
        }

        return result;
    }

    int popAtStack(int index) {
        if (index >= stacks.size() || stacks[index].empty()) return -1;

        if (index == stacks.size() - 1) return pop();

        int result = stacks[index].top();
        stacks[index].pop();

        availableStacks.insert(index);

        return result;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
