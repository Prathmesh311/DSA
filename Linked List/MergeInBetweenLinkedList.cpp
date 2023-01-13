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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* currNode = list1;

        ListNode* nodeB = new ListNode();

        //1st: find and store last replacable node
        int index = 0;
        while(currNode != NULL){
           if(index == b){
                nodeB = currNode->next;
            }
            else{
                currNode = currNode->next;
            }
            index++;
        }

        currNode = list1;
        ListNode* ans = currNode;

        //2nd: iterate through LL to find 1st replacable element
        index = 0;
        while(list1 != NULL){
            if(index+1 == a){
                //3rd: once 1st replacable element found add new LL 
                while(list2->next != NULL){
                    currNode->next = list2;
                    currNode = currNode->next;
                    list2 = list2->next;
                }

                //4th: attach old non-replacable LL at the end
                list2->next = nodeB;
                break;
            }
            else{
                currNode = currNode->next;
            }
            index++;
        }
        
        return ans;
    }
};
