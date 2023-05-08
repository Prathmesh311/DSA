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
    ListNode* swapPairs(ListNode* head) {
        ListNode* root =  new ListNode();
        root->next = head;
        ListNode* currHead = root;

        while(currHead != NULL && currHead->next != NULL && currHead->next->next != NULL){
            ListNode* secondNext = currHead->next->next->next;
            ListNode* firstElement = currHead->next;
            
            currHead->next =  currHead->next->next;
            currHead->next->next = firstElement;
            firstElement->next = secondNext;

            currHead = currHead->next->next;
            
        }
        return root->next;
    }
};
