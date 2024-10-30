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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> map;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i < size; i++){
                auto p = q.front();
                q.pop();

                int deviation = p.second;
                TreeNode* currNode = p.first;

                if(currNode == NULL){
                    continue;
                }

                map[deviation].push_back(currNode->val);

                
                q.push({currNode->left, deviation-1});
                q.push({currNode->right, deviation+1});
            }
        }


        vector<vector<int>> ans;
        for(auto p : map){
            vector<int> currCol;
            for(int node: p.second){
                currCol.push_back(node);
            }
            ans.push_back(currCol);
        }

        return ans;
    }
};
