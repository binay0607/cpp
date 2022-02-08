// for two root we have to find lowest common link node
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
     Node* left;
     Node* right;
    // constructor
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }
    
};




bool getpath(Node* root,int key, vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }



    if(getpath(root->left,key,path)||getpath(root->right,key,path)){
        return true;
    }

    path.pop_back();
    return false;
}
 int LCA(Node* root,int n1,int n2){
     vi path1,path2;
     if(!getpath(root,n1,path1)|| !getpath(root,n2,path2)){
            return -1;
     }  
     int pc;
   
     for(pc=0;pc<path1.size()&& path2.size();pc++){
 
         if(path1[pc]!=path2[pc]){
             break;
         }
     }


     return path1[pc-1];
 }


Node* LCA2(Node* root, int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* leftLCA= LCA2(root->left,n1,n2);
    Node* rightLCA= LCA2(root->right,n1,n2);
    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA!=NULL){
        return leftLCA;
    }
    return rightLCA;
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
    root->right->left->left=new Node(11);
   
   
    cout<<LCA(root,7,11);
    Node* lca=LCA2(root,7,11);
    cout<<lca->data<<nl;


    // 1
    // 2 3
    // 4 5 6 7
    // x x x x 11 x x x
}