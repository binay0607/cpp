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
int search(int inorder[], int start,int end,int curr){
    for(int i=start; i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
Node* buildtree(int postorder[], int inorder[], int start, int end){
     if(start>end){
         return NULL;
     }
     static int idx=0;   //interesting look o/p
     int curr= postorder[idx];
     cout<<idx<<" "<<curr <<nl;
     idx--;
     
     
     Node* node= new Node(curr);
     if(start==end){
         return node;
     }
     
     int pos=search(inorder, start,end,curr);
     node->right=buildtree(postorder,inorder,pos+1,end);
     node->left=buildtree(postorder,inorder,start, pos-1);
     
     return node;
}


void inorderprint(struct Node* root){
    if(root==NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int postorder[] ={4,2,5,3,1};
    int inorder[]= {4,2,1,5,3};
    cout<<postorder[-2]<<nl;
    Node * root=buildtree(postorder,inorder,0,4);
    inorderprint(root);
}