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
    TreeNode* constructTree(vector<int> &preorder, vector<int> &inorder, int &index, int left, int right){
        if(index >= preorder.size() || left > right){
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[index]);

        int divideIndex = -1;
        for(int i = left; i <= right; i++){
            if(inorder[i] == preorder[index]){
                divideIndex = i;
                break;
            }
        }
        index++;
        
        if(divideIndex != -1){
            node->left = constructTree(preorder, inorder, index, left, divideIndex-1);
            node->right = constructTree(preorder, inorder, index, divideIndex+1, right);
        }
        
        return node;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return constructTree(preorder, inorder, index, 0, preorder.size()-1);
    }
};
