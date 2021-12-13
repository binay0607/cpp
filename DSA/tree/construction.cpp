#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define li list<int>
#define nl "\n"
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define ppc __builtin_popcount
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ceel(a,b)   ((a+b-1)/b)
#define all(x)      (x).begin(),(x).end()
#define ll          long long
#define dp(n,k) int** dp = new int*[n+1];for(int i=0;i<=n;i++){dp[i] = new int[k+1];}
#define M           1000000007
#define INF         1e18

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    // constructor
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }
    
};
void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    struct Node* root=new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);

    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right= new Node(7);


    // traversals
    preorder(root);
    // 1 2 4 5 3 6 7 
    
    cout<<nl;
    inorder(root);
    // 4 2 5 1 6 3 7 

    cout<<nl;
    postorder(root);
    // 4 5 2 6 7 3 1
 


    // 1
    // 2 3
    // 4 5 6 7



}