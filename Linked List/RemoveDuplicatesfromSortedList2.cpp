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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while(head != NULL){
            if(head->next!=NULL && head->val == head->next->val){        //if current and next node is same
                while(head->next!=NULL && head->val == head->next->val){ //traverse until find diff element
                    head = head->next;
                }   
                prev->next = head->next;                                 //add to prev diff element
            }
            else{
                prev = prev->next;                                       
            }

            head = head->next;
        }
        
        return dummy->next;
    }
};
