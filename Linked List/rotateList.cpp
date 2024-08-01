/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0){
            return head;
        }

        int totalNodes = 0;
        ListNode* currNode = head;
        ListNode* tailNode;

        while(currNode != NULL){
            tailNode = currNode;
            currNode = currNode->next;
            totalNodes++;
        }

        int newHeadIndex =  (totalNodes - (k % totalNodes)) ;
        if(newHeadIndex == totalNodes){
            return head;
        }

        ListNode* newHead = head;
        currNode = head;
        ListNode* prevNode = head;

        while(newHeadIndex > 0){
            prevNode = currNode;
            currNode = currNode->next;
            newHeadIndex--;
        }

        newHead = currNode;
        tailNode->next = head;
        prevNode->next = NULL;

        return newHead;
    }
};
