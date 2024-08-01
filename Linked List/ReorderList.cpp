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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){        //Find middle of LL
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* before = nullptr;    
        ListNode* temp = slow->next;      //Temp is mid+1 element
        slow->next = NULL;

        while(temp){                      //reverse the second half of LL
            ListNode* after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }

        ListNode* root = new ListNode();
        ListNode* curr = root;

        while(before && head){           //Merge 2 LL
            curr->next = head;
            curr = curr->next;
            head = head->next;

            curr->next = before;
            curr = curr->next;
            before = before->next;
        }

        if(before){
            curr->next = before;
        }

        if(head){
            curr->next = head;
        }
    }
};
