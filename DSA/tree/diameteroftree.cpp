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
// naive approach------------------------------------------------
int height(btnode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

int diameter(btnode* root) {
	if (root == NULL) {
		return 0;
	}

	int option1 =1+ height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}
// ------------------------------------------------------------------

// optimal approach
pair<int,int> heightdiameter(btnode* root){
    if(root==NULL){
        return make_pair(0,0);
    }

    pair<int,int> ltree= heightdiameter(root->left);
    pair<int ,int> rtree= heightdiameter(root->right);
    int lh=ltree.first;
    int rh= rtree.first;
    int ld= ltree.second;
    int rd= rtree.second;
    int d= max(lh+rh+1, max(rd,ld));
    return make_pair(1+max(lh,rh), d);


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
    printliketree(root);
    // cout<<diameter(root)<<nl;
    pair<int ,int> hd=heightdiameter(root);
    cout<<"Height: "<<hd.first<<nl;
    cout<<"Diameter: "<<hd.second<<nl;
    // printtree(root);

}