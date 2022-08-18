#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define li list<int>
#define nl "\n"
#define ff first
#define ss second

void dfs( vector<vector<int>> &adj, vector<pair<int,int>> &inout, int node, int parent,int &currtime){
    inout[node].ff=currtime;
    currtime++;
    for(int el: adj[node]){
        if(el!=parent){
            dfs(adj,inout, el, node, currtime);
        }
    }
    inout[node].ss= currtime;
    currtime++;

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
    int currtime=0;
    vector<pair<int,int>> inout(n);
    dfs(adj,inout,0,-1,currtime);
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<inout[i].ff<<" "<<inout[i].ss<<nl;
    }
}


//from this we can easily find solve isancestor problem
// say A= ancestor  N=node , then-->
// intime(A)<= intime(N)<= outtime(N)<=  outtime(A)