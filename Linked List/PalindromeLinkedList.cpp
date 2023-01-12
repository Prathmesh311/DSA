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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }

    bool isPalindrome(ListNode* head) {

        //1st: Find middle of LL
        ListNode* middle = middleNode(head);

        //2nd: reverse LL next to middle node
        ListNode* temp = middle->next;
        middle->next = reverseList(temp);

        //3rd: compare 2 half lists
        ListNode* head1 = head;
        ListNode* head2 = middle->next;

        while(head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;

        
    }
};
