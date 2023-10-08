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

    ListNode* merge(ListNode* left, ListNode* right){
        
        ListNode* root = new ListNode();
        ListNode* curr = root;

        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }

        while(left && right){
            if(left->val < right->val){
                curr->next = left;
                curr = curr->next;
                left = left->next;
            }
            else{
                curr->next = right;
                curr = curr->next;
                right = right->next;
            }
        }

        if(left){
            curr->next = left;
        }
        if(right){
            curr->next = right;
        }

        return root->next;

    }

    ListNode* split(ListNode* head, int listLen){
        if(head == NULL || head->next == NULL){
            return head;
        }


        ListNode* firstRoot = new ListNode();
        firstRoot->next = head;

        int mid = listLen / 2;
        int nextHalf = listLen - mid;

        while(mid != 1){
            head = head->next;
            mid--;
        }


        ListNode* secondRoot = head->next;
        head->next = NULL;


        ListNode* left = split(firstRoot->next, listLen - nextHalf);
        ListNode* right = split(secondRoot, nextHalf);

        ListNode* mergedList = merge(left, right);

        return mergedList;
    }


    ListNode* sortList(ListNode* head) {
        int listLen = 0;
        ListNode* root = new ListNode();
        root->next = head;
        
        while(head != NULL){
            listLen++;
            head = head->next;
        }

        int mid = listLen/2;
        return split(root->next, listLen);
        
    }
};
