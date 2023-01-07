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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


        if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }

        ListNode* root = new ListNode(NULL);
        ListNode* currNode = root;
        

        while(list1 && list2){
            if(list1->val <= list2->val){
                currNode->next = list1;
                currNode = currNode->next;
                list1 = list1->next;
            }
            else{
                currNode->next = list2;
                currNode = currNode->next;
                list2 = list2->next;
            }
        }

        if(list1){
            currNode->next = list1;
        }
        if(list2){
            currNode->next = list2;
        }


        return root->next;
    }
};
