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
    TreeNode* buildTreeFromTraversal(vector<int>& preorder, vector<int>& inorder, int &i, int s, int e){

        if(i >= preorder.size() || s > e){
            return NULL;
        }

        int element = preorder[i];
        TreeNode* root = new TreeNode(element);

        int index = -1;
        for(int j=0; j < preorder.size(); j++){
            if(inorder[j] == element){
                index = j;
                break;
            }
        }

        i++;
        root->left = buildTreeFromTraversal(preorder, inorder, i, s, index-1);
        root->right = buildTreeFromTraversal(preorder, inorder, i, index+1, e);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        TreeNode* root = buildTreeFromTraversal(preorder, inorder, i, 0, inorder.size()-1);
        return root;
    }
};
