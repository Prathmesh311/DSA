/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
  
    Node* LCA(Node* root,int a, int b){   //Lowest common ancester
        if(root==NULL){
            return NULL;
        }
        
        if(root->data == a || root->data == b){
            return root;
        }
        
        Node* left =  LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);
        
        if(left != NULL && right != NULL){
            return root;
        }
        
        if(left != NULL){
            return left;
        }
        return right;
    }
    
    int search(Node* root, int key, int level){
        if(root == NULL){
            return -1;
        }
        
        if(root->data == key){
            return level;
        }
        
        int left = search(root->left, key, level+1);
        if(left != -1){
            return left;
        }
        
        return search(root->right, key, level+1);
      
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lcaRoot = LCA(root, a, b);     //Lowest common ancester
        
        int l1 = search(lcaRoot, a, 0);      //searching for depth in left and right subtree from LCA
        int l2 = search(lcaRoot, b, 0);
        
        return l1 + l2;
    }
};
