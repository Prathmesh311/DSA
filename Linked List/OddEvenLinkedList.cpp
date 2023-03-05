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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* root = head;
        ListNode* even = new ListNode();
        ListNode* evenRoot = even;
        ListNode* preNode = new ListNode();
        ListNode* lastOddNode = new ListNode();

        int odd = 1;
        while(head != NULL){
            if(odd == 0){
                ListNode* node = new ListNode(head->val);
                even->next = node;
                even = even->next;
                preNode->next = head->next;
                head= head->next;
                odd = 1;
            }
            else{
                preNode = head;
                lastOddNode = head;
                head = head->next;
                odd = 0;
            }

        }

        lastOddNode->next = evenRoot->next;

        return root;
        
    }
};
