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

    //Method2: faster than reverse method 90% faster
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode *currNode = head;

        int carry = 0;

        while(list1 != NULL && list2 != NULL){
            int value = list1->val + list2->val + carry;
            int currVal = value % 10;
            carry = value / 10;

            ListNode *newNode = new ListNode(currVal);
            currNode->next = newNode;
            currNode = currNode->next;
            list2 = list2->next;
            list1 = list1->next;
            
        }

        while(list1 != NULL){
            int value = list1->val + carry;
            int currVal = value % 10;
            carry = value / 10;

            ListNode *newNode = new ListNode(currVal);
            currNode->next = newNode;
            currNode = currNode->next;
            list1 = list1->next;
        }

        while(list2 != NULL){
            int value = list2->val + carry;
            int currVal = value % 10;
            carry = value / 10;

            ListNode *newNode = new ListNode(currVal);
            currNode->next = newNode;
            currNode = currNode->next;
            list2 = list2->next;
        }

        if(carry > 0){
            ListNode *newNode = new ListNode(carry);
            currNode->next = newNode;
        }

        return head->next;
    }
};
