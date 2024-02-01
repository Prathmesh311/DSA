class Codec {
public:
    void dfs(TreeNode* node, string& order) {
        if (!node) {
            order += "N,";
            return;
        }
        
        order += to_string(node->val) + ",";
        dfs(node->left, order);
        dfs(node->right, order);
    }

    string serialize(TreeNode* root) {
        string order;
        dfs(root, order);
        if (!order.empty())
            order.pop_back(); // Remove the trailing comma
        return order;
    }

    TreeNode* createTree(string& data) {
        if (data.empty() || data[0] == 'N') {
            if (data.size() >= 2) // Move to the next value
                data = data.substr(2);
            return nullptr;
        }

        int pos = data.find(",");
        string str = data.substr(0, pos);
        data = data.substr(pos + 1);

        TreeNode* newNode = new TreeNode(stoi(str));
        newNode->left = createTree(data);
        newNode->right = createTree(data);
        return newNode;
    }

    TreeNode* deserialize(string data) {
        return createTree(data);
    }
};
