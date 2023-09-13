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
        ListNode* node = head;
        map<int, int> map;
        int index = 0;
        int len = 0;

        while(node != NULL){
            len++;
            node = node->next;
        }
        
        node = head;
        while(node != NULL){
            if(index < len/2){
                int pos = len - 1 - index;
                map[pos] = node->val;
            }else{
                map[index] = map[index] + node->val;
            }

            node= node->next;
            index++;
        }

        int maxTwin = 0;
        for(auto p: map){
            maxTwin = max(maxTwin, p.second);
        }
        return maxTwin;
    }
};
