/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    deque<NestedInteger> deque;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        deque.assign(nestedList.begin(), nestedList.end());
    }
    
    int next() {
        int value = 0;
        if(deque.front().isInteger()){
            value =  deque.front().getInteger();
            deque.pop_front();
        }

        return value;
    }
    
    bool hasNext() {
        while(!deque.empty()){
            if(deque.front().isInteger()){
                return true;
            }else{
                vector<NestedInteger> list = deque.front().getList();
                deque.pop_front();
                
                for(int i = list.size()-1; i >= 0; i--){
                    deque.push_front(list[i]);
                }
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
