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
    TreeNode* buildTreeFromTraversal(vector<int>& inorder, vector<int>& postorder, int &i, int start, int end){

        //base case
        if(i < 0 || start > end){
            return NULL;
        }

        int element = postorder[i];
        TreeNode* root = new TreeNode(element);

        int position = -1;
        for(int j=0; j < inorder.size(); j++){
            if(inorder[j] == element){
                position = j;
                break;
            }
        }

        i--;
        root->right = buildTreeFromTraversal(inorder, postorder, i, position+1, end);
        root->left  = buildTreeFromTraversal(inorder, postorder, i, start, position-1);
        
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size()-1;
        return buildTreeFromTraversal(inorder, postorder, i, 0, postorder.size()-1);
    }
};
