#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define li list<int>
#define nl "\n"
#define ff first
#define ss second

void dfs( vector<vector<int>> &adj, int node, int parent, vector<int > &eulortour, vector<int > &left, vector<int> & right){
    eulortour.push_back(node+1);
    left[node]=eulortour.size();
    for(int el: adj[node]){
        if(el!=parent){
            dfs(adj, el, node, eulortour, left, right);
        }
    }
    eulortour.push_back(node+1);
    right[node]=eulortour.size();
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> eulortour, left(n), right(n);
    dfs(adj, 0, -1, eulortour, left, right); 
    for(int node: eulortour){
        cout<<node<<" ";
    }cout<<nl;
    
}