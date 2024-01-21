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

    void dfs(TreeNode* root, map<int, vector<int>> &nbr, map<int, int> &visited, int prevNode){
        if(root == NULL){
            return;
        }

        visited[root->val] = 0;
        nbr[root->val].push_back(prevNode);

        if(root->left != NULL){
            nbr[root->val].push_back(root->left->val);
            dfs(root->left, nbr, visited, root->val);
        }

        if(root->right != NULL){
            nbr[root->val].push_back(root->right->val);
            dfs(root->right, nbr, visited, root->val);
        }

    }

    void bfs(map<int, vector<int>> nbr, map<int,int> &visited, vector<int> &ans, int target, int k){
        queue<pair<int, int>> q;
        q.push({target, k});

        while(!q.empty()){
            pair<int, int> p = q.front();
            int currNode = p.first;
            int rem = p.second;
            q.pop();


            visited[currNode] = 1;

            if(rem == 0){
                ans.push_back(currNode);
            }else{
                for(int num : nbr[currNode]){
                    if(num != -1 && visited[num] == 0){
                        q.push({num, rem-1});
                    }
                }
            }            
        }


    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<int, vector<int>> nbr;
        map<int,int> visited;

        dfs(root, nbr, visited, -1);
        bfs(nbr, visited, ans, target->val, k);

        return ans;
    }
};
