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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }


        ListNode* prevNode = NULL;

        while(slow != NULL){
            ListNode* nextNode = slow->next;
            slow->next = prevNode;
            prevNode = slow;
            slow = nextNode;
        }

        ListNode* secondHead = prevNode;
        ListNode* firstHead = head;
        
        int maxSum= 0;
        while(secondHead != NULL){
            maxSum = max(maxSum, (secondHead->val + firstHead->val));
            secondHead = secondHead->next;
            firstHead = firstHead->next;
        }


        return maxSum;
    }
};
