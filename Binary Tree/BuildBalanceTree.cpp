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

node* buildBalanceTree(int *a, int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(a[mid]);

    root->left = buildBalanceTree(a, s, mid-1);
    root->right = buildBalanceTree(a, mid+1, e);


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
  
   int a[] = {1,2,3,4,5,6,7};
   int n = 7;

   node* root = buildBalanceTree(a, 0, n-1);
   BFS(root);

    return 0;
}