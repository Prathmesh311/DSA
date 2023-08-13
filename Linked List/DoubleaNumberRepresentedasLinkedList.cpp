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
    int traverse(ListNode* node){
        if(node == NULL){
            return 0;
        }
        
        int num = traverse(node->next);
        int currNewNum = node->val * 2 + num;
        node->val = currNewNum % 10;
        return currNewNum / 10;
    }
    
    
    ListNode* doubleIt(ListNode* head) {
        int num = traverse(head);
        
        if(num > 0){
            ListNode* newHead = new ListNode(num, head);
            return newHead;
        }
        
        return head;
    }
};
