class Solution {
public:
    ListNode* reverse(ListNode* currNode, ListNode* preNode){
        if(currNode == NULL){
            return preNode;
        }

        ListNode* root =  reverse(currNode->next, currNode);
        currNode->next = preNode;                            //Changing direction of arrow
        return root;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //1st: Reverse both LL
        ListNode* reverseL1 = reverse(l1, NULL);
        ListNode* reverseL2 = reverse(l2, NULL);
      

        //2nd: add reversed LL's and store in new LL
        ListNode* ans = new ListNode(0);
        ListNode* headAns = ans;
        int carry = 0;
       

        while(reverseL1 != NULL || reverseL2 != NULL){
            int data = 0;
            if(reverseL1 == NULL){
                data = (reverseL2->val) + carry;
            }
            else if(reverseL2 == NULL){
                data = (reverseL1->val) + carry;
            }else{
                data = (reverseL1->val + reverseL2->val) + carry;
            }
          

            ListNode* currNode = new ListNode(data%10);
            ans->next = currNode;
            ans = ans->next;


            carry = data / 10;
                
            if(reverseL1 != NULL){
                reverseL1 = reverseL1->next;
            }
            if(reverseL2 != NULL){
                reverseL2 = reverseL2->next;
            }
        
        }

        if(carry != 0){
            ListNode* currNode = new ListNode(carry);
            ans->next = currNode;
        }
    

        return reverse(headAns->next, NULL);
    }
};