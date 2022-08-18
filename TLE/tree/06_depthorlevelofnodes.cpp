#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define li list<int>
#define nl "\n"
#define ff first
#define ss second

void dfs( vector<vector<int>> & adj, vector<int> &depth,int node,int parent, int dep){
    depth[node]=dep;
    for( int el: adj[node]){
        if(el!=parent){
            dfs(adj, depth, el, node, dep+1);
        }
    }
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
    vector<int> depth(n);
    int dep=0;
    dfs(adj, depth, 0, -1,dep);
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<depth[i]<<nl;
    }

}