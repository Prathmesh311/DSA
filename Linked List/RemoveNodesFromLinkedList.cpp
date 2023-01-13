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
    ListNode* removeNodes(ListNode* head) {
        if(head->next == NULL){
            return head;
        }

        ListNode* greaterNode = removeNodes(head->next);

        if(greaterNode->val <= head->val){
            head->next = greaterNode;
            return head;
        }

        return greaterNode;
    }
};
