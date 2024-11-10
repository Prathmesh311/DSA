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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>> levelMap;
        map<int, vector<int>> verticalOrder;

        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i < size; i++){
                auto p = q.front();
                q.pop();

                TreeNode* currNode = p.first;
                int col = p.second;

                if(currNode == NULL){
                    continue;
                }

                levelMap[col].push_back(currNode->val);

                q.push({currNode->left, col-1});
                q.push({currNode->right, col+1});
            }

            for(auto m : levelMap){
                vector<int> currNodes = m.second;
                sort(currNodes.begin(), currNodes.end());
                
                for(int num : currNodes){
                    verticalOrder[m.first].push_back(num);
                }
            }
            levelMap.clear();
        }

        vector<vector<int>> finalOrder;

        for(auto v : verticalOrder){
            finalOrder.push_back(v.second);
        }

        return finalOrder;
    }
};
