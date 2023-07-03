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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        queue<TreeNode*> q;
        int size;

        q.push(root);
       
        while(!q.empty()){
            size = q.size();
            long sum = 0;

            for(int i = 1; i <= size; i++){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left != NULL){
                q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
    
            avg.push_back((double)sum/size);
            
        }


        return avg;
    }
};
