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
    typedef pair<int, ListNode*> node;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<node, vector<node>, greater<node>> pq;  

        ListNode* root = new ListNode();           //created new list root node
        ListNode* currNode = root;

        for(int i=0; i < lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});//push 1st nodes of each list in minHeap
            }
        }

       
        while(!pq.empty()){
            int minValue = pq.top().first;
            ListNode* minNode = pq.top().second;   //extracting min node from heap
           
            currNode->next = minNode;              //adding min node to new list
            currNode = currNode->next;
           
            pq.pop();

            if(minNode->next){
                pq.push({minNode->next->val, minNode->next}); //pushing next node from list to heap
            }
            
        }

        return root->next;
    }
};
