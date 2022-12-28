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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        //traverse through BST
        if(key < root->val){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
            return root;
        }
        //If node found
        else if(key == root->val){
            //case1: node is leaf node
            if(root->left == NULL && root->right ==NULL){
                delete root;
                return NULL;
            }

            //case2: node has only 1 child left/right
            else if(root->left ==NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //case3: node has both childs
            TreeNode* replace = root->right;

            while(replace->left != NULL){
                replace = replace->left;
            }

            root->val = replace->val;
            root->right = deleteNode(root->right, replace->val);
            return root;
            
        }

        return root;
        
    }
};
