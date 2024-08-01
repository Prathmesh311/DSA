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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k ==0){
            return head;
        }

        int counter = 1;
        ListNode* currNode = head;
        while(currNode->next){                //counting length of LL
            counter++;
            currNode = currNode->next;
        }

        ListNode* tail = currNode;
        int partition = (k%counter);          //finding the index to rotate the LL
        
        if(partition == 0){
            return head;
        }

        int breaker = counter - partition;
     
        currNode = head; 
        ListNode* tempNode;
        while(breaker != 0){                 //at breaking index break the LL
            if(breaker == 1){
                tempNode = currNode->next;
                currNode->next = NULL;
                break;
            }else{
                currNode = currNode->next;
            }
            breaker--;
        }

        ListNode* headNode = tempNode;

        while(tempNode->next != NULL){
            tempNode = tempNode->next;
        }          
        tempNode->next = head;              //formming new LL

        return headNode;
    }
};
