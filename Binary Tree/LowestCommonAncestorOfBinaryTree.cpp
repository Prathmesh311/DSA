/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == p->val or root->val == q->val){   //If node found return
            return root;
        }

        TreeNode* leftVal = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightVal = lowestCommonAncestor(root->right, p, q);

        if(leftVal != NULL && rightVal != NULL){         //If both left and right subtree contains nodes return root node
            return root;
        }

        if(leftVal != NULL){   //return left node
            return leftVal;
        }
        return rightVal;
    }
};
