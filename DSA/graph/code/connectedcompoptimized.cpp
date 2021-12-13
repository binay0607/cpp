// using adjecancy list
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vvi vector<vi> 
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

void dfs(vvi &adj,int index,bool visited[],vi & comp){
    comp.push_back(index);
    visited[index]=true;
    for(auto v:adj[index]){
        if(visited[v]==false){
            dfs(adj,v,visited,comp);
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;cin>>t;
while(t--){
    int n,m;cin>>n>>m;
    vvi adj(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
       
    }
     bool visited[n+1];
        memset(visited,false,sizeof(visited));

        for(int i=1;i<=n;i++){
        
            if(!visited[i]){
                vi comp;
                dfs(adj,i,visited,comp);
                sort(all(comp));
                for(int j=0;j<comp.size();j++){
                    cout<<comp[j]<<" ";
                }
                cout<<nl;
            }
            
        }
}
}