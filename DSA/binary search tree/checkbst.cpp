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
bool checkbst(btnode* root){
    if(root==NULL){
        return true;
    }
    bool ltree= checkbst(root->left);
    bool rtree= checkbst(root->right);

    if(ltree && rtree){
        int sum=0;
        if((root->left &&(root->left->data)<(root->data)) || root->left==NULL){
            sum++;
        }

        if(root->right ){
            if((root->right->data)>=(root->data))sum++;
        }else{
            sum++;
        }
        if(sum==2){return true;}
    }
    return false;
   

    
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
    cout<<checkbst(root);
    // printtree(root);

}