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
void printliketree(btnode* root){
    queue<btnode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        btnode* front= q.front();
        if(front==NULL)break;
        while(front){
            cout<<front->data<<" ";
            
            // for mirror just switch the seq
            if(front->left){
                q.push(front->left);

            }
            if(front->right){
                q.push(front->right);
            }
            q.pop();
            front=q.front();
        }
        cout<<nl;
        q.pop();
        q.push(NULL);

    }
}

btnode* in_pre(int pre[],int in[],int n, int ins,int ine, int pres,int pree){
    if(pres>pree||ins>ine){
        return NULL;
    }
    btnode* root= new btnode(pre[pres]);
    // cout<<root->data<<" "<<pres<<nl;
    int lpres=pres+1;
    int lins=ins;
    int i;
    for( i=ins;i<=ine;i++){
        if(in[i]==pre[pres]){
            break;
        }
    }
    // cout<<i<<" i"<<nl;
    int line=i-1;
    int lpree=lpres+(line-lins);
    int rpres=lpree+1;
    int rpree=pree;
    int rins=i+1;
    int rine=ine;
    btnode* leftt=in_pre(pre, in, n,  lins, line, lpres,lpree);
    btnode* rightt=in_pre(pre,in, n, rins,rine,rpres,rpree);
    root->left=leftt;
    root->right=rightt;
    return root;
}
// the header file is handling taking input and printing;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    // vector<int> nodes;
    // int node;
    // while(cin>>node){
    //     nodes.push_back(node);
    // }

    // btnode* root= takeinput(nodes);
    // printtree(root);
    int n;cin>>n;
    int pre[n];
    int in[n];
    rep(i,0,n)cin>>pre[i];
    rep(i,0,n)cin>>in[i];
    // cout<<in[4]<<nl;
    btnode* root=in_pre(pre,in,n,0,n-1,0,n-1);
    printliketree(root);
    // cout<<root->data<<nl;

}