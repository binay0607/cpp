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


void printlevelwise(btnode* root){
    queue<btnode*> q;
    q.push(root);
    while(!q.empty()){
        btnode* front= q.front();
        q.pop();
        int l=-1,r=-1;
        if(front->left){
            l=front->left->data;
            q.push(front->left);

        }
        if(front->right){
            r=front->right->data;
            q.push(front->right);
        }
        cout<<front->data<<": "<<"L"<<l<<" "<<"R"<<r<<nl;
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
    printlevelwise(root);

}