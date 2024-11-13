/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL){
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }

        Node* currNode = head;

        while(currNode->next != head){
            if(currNode->val <= insertVal && insertVal <= currNode->next->val){
                Node* newNode = new Node(insertVal, currNode->next);
                currNode->next = newNode;
                return head;
            }
            else if(currNode->val > currNode->next->val){
                if(currNode->val <= insertVal || insertVal <= currNode->next->val){
                    Node* newNode = new Node(insertVal, currNode->next);
                    currNode->next = newNode;
                    return head;
                }
            }
            currNode = currNode->next;
        }

        Node* newNode = new Node(insertVal, currNode->next);
        currNode->next = newNode;

        return head;
    }
};
