// structure to define a node of the doubly linked list in C++
class Node{
public:
    int k;
    int val;
    Node* prev;
    Node* next;
    
    Node(int key, int value) {
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};


class LRUCache {
private:
    Node* head;
    Node* tail;
    int capacity = 0;
    unordered_map<int, Node*> map;

    //Removes node from DLL
    void remove(Node* curr){
        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    //adds node after head in DLL
    void addNode(Node* currNode){
        Node* nextNode = head->next;

        head->next = currNode;
        nextNode->prev = currNode;

        currNode->prev = head;
        currNode->next = nextNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        //initializing head and tail of DLL
        head = new Node(0, 0);    
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    

    int get(int key) {
        //If node alredy present in DLL remove it from it's original position and add at front of DLL
        if(map.find(key) != map.end()){
            remove(map[key]);
            addNode(map[key]);
            //return the value
            return map[key]->val;
        }

        //return -1 if element not present in DLL
        return -1;    
    }
    
    void put(int key, int value) {
        //If element present in DLL remove it
        if(map.find(key) != map.end()){
            remove(map[key]);
            map.erase(key);
        }

        //If DLL capacity full then remove element from last(before tail) which is least recently used
        if(map.size() == capacity){
             Node* tailPrev = tail->prev;
            remove(tailPrev);
            map.erase(tailPrev->k);
            delete tailPrev;
        }
        
        //Add new node at front (after head)
        Node* currNode = new Node(key, value);
        addNode(currNode);
        map[key] = currNode;  //update map
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
