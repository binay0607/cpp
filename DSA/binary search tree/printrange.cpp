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
void printinrange(btnode* root,int l,int r){
    if(root==NULL){
        return;
    }
    if(root->data>=l && root->data<=r){
        printinrange(root->left,l,r);
        cout<<root->data<<" ";
        printinrange(root->right,l,r);
    }else if(r<root->data){
        printinrange(root->left,l,r);
    }else{
       printinrange(root->right,l,r); 
    }
    
}

// the header file is handling taking input and printing;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    vector<int> nodes;
    int node;
    while(cin>>node){
        nodes.push_back(node);
    }

    btnode* root= takeinput(nodes);
    int l=nodes[nodes.size()-2];
    int r=nodes[nodes.size()-1];
    // cout<<l<<" "<<r<<nl;
    printinrange(root,l,r);
    // printtree(root);

}