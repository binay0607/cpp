#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define li list<int>
#define nl "\n"
#define ff first
#define ss second

void dfs(vector<vector<int>> &adj, vector<int> &parent,vector<int>&depth, int node, int prnt,int dep){
    parent[node]=prnt;
    depth[node]=dep;
    for(int el: adj[node]){
        if(el!=prnt){
            dfs(adj, parent,depth, el, node, dep+1);
        }
    }
}
int kthparent(vector<vector<int>> &parents,int x,int k){
    for(int i=0;i<=log2(k);i++){
        if((1<<i)&k){
            x=parents[x][i];
        }
    }
    return x;
}


int getlca( vector<vector<int>> &adj,vector<int>&depth, vector<vector<int>> &parents, int s, int e,int n){
    if(depth[s]>depth[e]){
        swap(s,e);
    }
    e= kthparent(parents,e, depth[e]-depth[s]);
    //now both the node are at a same level

    if(s==e){
        return s;
    }
    for(int i=log2(n);i>=0;i--){
        int parent1= parents[s][i];
        int parent2= parents[e][i];
        //this is like binay tree it won't let go the index out of lca
        if(parent1!=parent2 && parent1!=-1 && parent2!=-1){
            s=parent1;
            e=parent2;
        }
    }
    return parents[s][0];
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
    vector<int> depth(n);
    dfs(adj, parent,depth, 0, -1,0);
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

    int s,e;cin>>s>>e;
    int lca=getlca(adj,depth, parents, s-1, e-1,n)+1;
    cout<<lca<<nl;
    //after getting lca we can easily find the path between two nodes
    //from both go till lca and merge the list

    // now to find the dist between two nodes;
    cout<<depth[s-1]+depth[e-1]- 2* depth[lca-1];
    
    
}
