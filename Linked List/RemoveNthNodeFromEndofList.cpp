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
    //approach 1: fast-slow pointer (2 pointer) / 100% faster
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while(n > 0){
            fast = fast->next;
            n--;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }

    //approach 2: recursive - slower
    int removeNthElement(ListNode* head, int n){
        if(head == NULL){       //If reach at last of LL return
            return n;
        }

        n = removeNthElement(head->next, n);
        if(n == 0){                          //found Nth element from last to remove 
            head->next = head->next->next;   //drop the node
            return -1;
        }
        return n-1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = new ListNode(0, head);  //create new root node to keep track of LL if 1st node is removed
       
        int num = removeNthElement(root, n);

        return root->next;

    }
};
