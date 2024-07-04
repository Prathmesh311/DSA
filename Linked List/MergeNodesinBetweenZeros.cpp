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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* root = new ListNode();

        ListNode* prevNode = root;
        ListNode* currNode = head->next;

        int currSum = 0;

        while(currNode != NULL){
            if(currNode->val == 0){
                ListNode* newNode = new ListNode(currSum);
                prevNode->next = newNode;
                prevNode = newNode;
                currSum = 0;
            }else{
                currSum += currNode->val;
            }
            currNode = currNode->next;
        }

        return root->next;
    }
};
