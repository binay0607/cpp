// we have to store the left +right + its own data for a node at all level
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
// sum of all nodes
int sum(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
}


int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

bool isbalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(!isbalanced(root->left)){
        return false;
    }
    if(!isbalanced(root->right)){
        return false;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    
    if(abs(lh-rh)<=1){
        return true;
    }
    return false;
}
// optimised
bool isbalancedopt(Node* root,int* height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(!isbalancedopt(root->left,&lh)){
        return false;
    }
    if(!isbalancedopt(root->right,&rh)){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    return false;
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
    cout<<isbalanced(root)<<nl;
    int height=0;
    cout<<isbalancedopt(root, &height);


    // 1
    // 2 3
    // 4 5 6 7
}