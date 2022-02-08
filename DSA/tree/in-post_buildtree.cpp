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

btnode* in_post(int post[],int in[],int n, int ins,int ine, int pos,int poe){
    if(pos>poe||ins>ine){
        return NULL;
    }
    btnode* root= new btnode(post[poe]);
    // cout<<root->data<<" "<<pres<<nl;
    int lpos=pos;
    int lins=ins;
    int i;
    for( i=ins;i<=ine;i++){
        if(in[i]==post[poe]){
            break;
        }
    }
    // cout<<i<<" i"<<nl;
    int line=i-1;
    int lpoe=lpos+(line-lins);
    int rpos=lpoe+1;
    int rpoe=poe-1;
    int rins=i+1;
    int rine=ine;
    btnode* leftt=in_post(post, in, n,  lins, line, lpos,lpoe);
    btnode* rightt=in_post(post,in, n, rins,rine,rpos,rpoe);
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
    int post[n];
    int in[n];
    rep(i,0,n)cin>>post[i];
    rep(i,0,n)cin>>in[i];
    // cout<<in[4]<<nl;
    btnode* root=in_post(post,in,n,0,n-1,0,n-1);
    printliketree(root);
    // cout<<root->data<<nl;

}