// we find by maintaining a parent vector
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define li list<int>
#define nl "\n"

void dfs(vector<vector<int>> &adj, vector<int> &parent, int node, int prnt){
    parent[node]=prnt+1;
    for(int el: adj[node]){
        if(el!=prnt){
            dfs(adj, parent, el, node);
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
    vector<int> parent(n);
    dfs(adj, parent, 0, -1);
    // for(int i=0;i<n;i++){
    //     cout<<i+1<<" "<<parent[i]<<nl;
    // }
    int node, ancestor;cin>>node>>ancestor;
    
    int temp=node;
    int t=3;
    while(parent[temp-1]!=0){
        cout<<temp<<" "<<parent[temp-1]<<nl;
        if(parent[temp-1]==ancestor-1){
            cout<<ancestor<<"  is an ancestor of node "<<node<<nl;
            return 0;
        }
        temp=parent[temp-1];
    }
    cout<<ancestor<<"  is not an ancestor of node "<<node<<nl;

}

// in this was we can find LCA- lowest common ancestor of two nodes
//first we store path from node to root for both the nodes in vector
// then by binarysearch we find the first element that is common in both the vector;