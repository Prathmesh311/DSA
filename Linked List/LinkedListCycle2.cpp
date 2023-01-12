/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, bool> visited;
        ListNode* node = head;

        while(node && visited.find(node) == visited.end()){
            visited.insert({node, true});
            node = node->next;
        }

        if(visited[node] == true){
            return node;
        }
        return NULL;
    }
};
