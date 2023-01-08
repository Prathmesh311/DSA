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
    ListNode* reverse(ListNode* currNode, ListNode* preNode){
        if(currNode == NULL){
            return preNode;
        }

        ListNode* root =  reverse(currNode->next, currNode);
        currNode->next = preNode;                            //Changing direction of arrow
        return root;
      
    }

    ListNode* reverseList(ListNode* head) {

        return reverse(head, NULL);
    }
};
