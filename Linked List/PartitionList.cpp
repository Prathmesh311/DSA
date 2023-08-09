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
    ListNode* partition(ListNode* head, int x) {
        ListNode* greaterHead = new ListNode();
        ListNode* greaterLL = greaterHead;
        ListNode* smallerHead = new ListNode();
        ListNode* smallerLL = smallerHead;

        while(head){
            if(head->val >= x){
                greaterLL->next = head;
                greaterLL = greaterLL->next;
            }
            else{
                smallerLL->next= head;
                smallerLL = smallerLL->next;
            }

            head= head->next;
        }

        greaterLL->next = NULL;
        smallerLL->next = greaterHead->next;

        return smallerHead->next;
    }
};
