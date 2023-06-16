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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<int> levelSum;


        q.push({root, 0});

        while(!q.empty()){
            pair<TreeNode*,int> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int level = p.second;

            if(node == NULL){
                continue;
            }

            if(levelSum.size() <= level){
                levelSum.push_back(node->val);
            }else{
                levelSum[level] += node->val;
            }
            
            q.push({node->left, level+1});
            q.push({node->right, level+1});
        }

        int maxValue = levelSum[levelSum.size()-1];
        int maxIndex = levelSum.size()-1;
        for(int i=levelSum.size()-2; i >= 0; i--){
            if(maxValue <= levelSum[i]){
                maxIndex = i;
                maxValue = levelSum[i];
            }
        }

        return maxIndex+1;
        
    }
};
