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

    //Method 2: using fast and slow pointer
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;


        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                slow = head;
               
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;   
        
    }
};
