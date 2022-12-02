#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void BFS(node* root){
    queue<node*> q;
    vector<vector<int>> levels;
    
    q.push(root);

    while(!q.empty()){
        node* n = q.front();
        q.pop();
        cout<<n->data<<", ";
        
        
        if(n->left){
            q.push(n->left);
        }
        if(n->right){
            q.push(n->right);
        }
    }
    return;
}

int main(){
    node* root = buildTree();
    BFS(root);

    return 0;
}