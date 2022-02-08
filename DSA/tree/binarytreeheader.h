#include<bits/stdc++.h>
using namespace std;
class btnode{
    public:
    int data;
    btnode* left;
    btnode* right;

    btnode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void printtree(btnode* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printtree(root->left);
	printtree(root->right);
}

btnode* takeinput( vector<int> nodes){
    int idx=0;
    btnode* root= new btnode(nodes[idx]);
    idx++;
    queue<btnode*> q;
    q.push(root);
    while(!q.empty()){
        btnode* front=q.front();
        q.pop();
        if(nodes[idx]!=-1){
            btnode* lchild=new btnode(nodes[idx]);
            front->left=lchild;
            q.push(lchild);
        }
        idx++;
        if(nodes[idx]!=-1){
            btnode* rchild= new btnode(nodes[idx]);
            front->right= rchild;
            q.push(rchild);
        }
        idx++;

    }
    return root;
}