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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;
        int maxDistance = 0;

        int startIndex = -1;
        int prevIndex = -1;
        int index = 1;

        ListNode* prevNode = head;
        ListNode* currNode = head->next;


        while(currNode->next != NULL){
            if((prevNode->val < currNode->val && currNode->val > currNode->next->val) || 
                (prevNode->val > currNode->val && currNode->val < currNode->next->val)){
                
                if(prevIndex != -1){
                    minDistance = min(minDistance, index - prevIndex);
                    maxDistance = max(maxDistance, index - startIndex);
                }else{
                    startIndex = index;
                }
                prevIndex = index;
            }

            prevNode = currNode;
            currNode = currNode->next;
            index++;
        }

        vector<int> result = {minDistance == INT_MAX ? -1 : minDistance, maxDistance == 0 ? -1 : maxDistance};
        return result;
    }
};
