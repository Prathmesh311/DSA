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
    ListNode* makeReverse(ListNode* head, int left, int right, vector<ListNode*>& nodes, int index){
        if(head == NULL){
            return NULL;
        }

        if(left <= index+1 && index+1 <= right){      //Store nodes to be reversed in vector
            nodes.push_back(head);
        }

        ListNode* nextNode = makeReverse(head->next, left, right, nodes, index+1);

        if(left <= index+1 && index+1 <= right){      //If at the place of reverse
    
            int reverseIndex = (nodes.size()-1) - (index+1 - left);  
            ListNode* reverseNode = nodes[reverseIndex];
            reverseNode->next = nextNode;

            return reverseNode;
        }
        else{
            head->next = nextNode;
        }

        return head;
    }


    ListNode* reverseBetween(ListNode* head, int left, int right) {
       vector<ListNode*> nodes;

       return makeReverse(head, left, right, nodes, 0);
    }
};
