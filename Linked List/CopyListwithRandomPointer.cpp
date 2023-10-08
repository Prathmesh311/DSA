/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> dummyList;
        Node* root = new Node(0);
        root->next = head;

        while(head){                           //First created the soppy node for each node in list
            Node* copy = new Node(head->val);
            dummyList[head] = copy;
            head = head->next;
        }

        head = root->next;
        

        while(head){                          //Iterate over all dumynodes and set their pointers appropriately
            Node* copy = dummyList[head];
            copy->next = dummyList[head->next];
            copy->random = dummyList[head->random];
            head = head->next;
        }


        return dummyList[root->next];
        
    }
};
