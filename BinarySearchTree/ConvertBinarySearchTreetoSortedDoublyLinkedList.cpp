/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    void convertTree(Node* root, Node* &first, Node* &last){
        if(root == NULL){
            return;
        }

        convertTree(root->left, first, last);

        if(last == NULL){
            first = root;
            last = root;
        }else{
            root->left = last;
            last->right = root;

            last = root;
        }
        
        convertTree(root->right, first, last);
    }

    Node* treeToDoublyList(Node* root) {
        if(root == NULL){
            return NULL;
        }
        Node* first = NULL;
        Node* last = NULL;

        convertTree(root, first, last);

        first->left = last;
        last->right = first;

        return first;
    }
};
