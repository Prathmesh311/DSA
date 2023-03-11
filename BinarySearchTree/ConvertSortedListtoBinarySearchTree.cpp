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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode* head, ListNode* tail){     //Find middle of curr LinkedList
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast != tail && fast->next != tail){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    TreeNode* createBST(ListNode* head, ListNode* tail){
        if(head == tail){          //return if reach on same element
            return NULL;
        }
        
        if(head->next == tail){    //return if only 1 element is remaining
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
      
        ListNode* middle = findMiddle(head, tail);  //Find middle node in LinkedList

        TreeNode* root = new TreeNode(middle->val); //create TreeNode from middle element of LL
 
        root->left = createBST(head, middle);       //pass  1st half of linked list to create BST
        root->right = createBST(middle->next, tail);//pass  2nd half of linked list to create BST

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
       return createBST(head, NULL);
    }
};
