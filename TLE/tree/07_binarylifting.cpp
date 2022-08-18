#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define li list<int>
#define nl "\n"
#define ff first
#define ss second

//this is helpful to find kth parent of any node
void dfs(vector<vector<int>> &adj, vector<int> &parent, int node, int prnt){
    parent[node]=prnt;
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
    vector<vector<int>> parents(n, vector<int> (log2(n)+5,-1));
    for(int i=1;i<n;i++){
        parents[i][0]=parent[i];
    }
    
    for(int i=1;i<log2(n)+5; i++){
        for(int j=1;j<n;j++){
            if(parents[j][i-1]!=-1){
                parents[j][i]= parents[parents[j][i-1]][i-1];
            }
        }
    }
    // finding the kth parent of a node
    //use the set bits of k
    int node,k;cin>>node>>k;
    // cout<<node<<" "<<k<<nl;
    int x=node--;
    for(int i=0;i<=log2(k);i++){
        if((1<<i)&k){
            x=parents[x][i];
        }
    }
    cout<<x+1<<nl;
    
    
}
// this binary lifting can be used to find lca
// here we don't need to store vector for path as we can find the mid node in one go 
// via this binay lifting method
// but we do to calculate depth too