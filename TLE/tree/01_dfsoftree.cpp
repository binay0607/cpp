#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

void dfs( vector<vector<int>> &adj, vector<int> &seq, int node, int parent ){
    seq.push_back(node+1);
    for(int el:adj[node] ){
        if(el!=parent){
            dfs(adj, seq,el, node);
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    //taking input of tree in adj list form
    int n;cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> seq;
    dfs(adj, seq, 0, -1);
    for(int el:seq){
        cout<<el<<" ";
    }cout<<nl;



}