#include<bits/stdc++.h>
#include "binarytreeheader.h"
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
#define fs(x)	 	cout<<fixed<<showpoint<<setprecision((x))
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ceel(a,b)   ((a+b-1)/b)
#define all(x)      (x).begin(),(x).end()
#define ll          long long
#define dp2(n,k) int** dp = new int*[n+1];for(int i=0;i<=n;i++){dp[i] = new int[k+1];}
#define M           1000000007
#define INF         1e18

btnode* maketreefromsortedarray(vector<int> nodes, int si, int ei){
    if(si>ei){
        return NULL;
    }
    int mid= (si+ei)/2;
    btnode* root= new btnode(nodes[mid]);
    btnode* ltree= maketreefromsortedarray(nodes,si,mid-1);
    btnode* rtree= maketreefromsortedarray(nodes,mid+1,ei);
    root->left= ltree;
    root->right= rtree;
    return root;
}
void preorder(btnode* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// the header file is handling taking input and printing;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    // vector<int> nodes(n);
    // int node;
    // while(cin>>node){
    //     nodes.push_back(node);
    // }

    // btnode* root= takeinput(nodes);
    int n;cin>>n;
    vector<int> nodes(n);
    for(int i=0;i<n;i++){
        cin>>nodes[i];
    }
    btnode * root= maketreefromsortedarray(nodes,0,n-1);
    preorder(root);
    // printtree(root);

}