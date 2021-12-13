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


void rightview(Node* root){
    if(root==NULL){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        rep(i,0,n){
            Node* curr= q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }

        }
        
    }
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
    rightview(root);
   
 


    // 1
    // 2 3
    // 4 5 6 7
    // x x x x 11 x x x
}