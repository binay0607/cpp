// Islands

// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa. Can you count the number of connected groups of islands?
// Input Format:
// The first line of input will contain T(number of test cases), each test case follows as.
// Line 1: Two Integers N and M (separated by space)
// Next 'M' lines, each have two space-separated integers, 'u' and 'v', denoting that there exists an edge between Vertex 'u' and Vertex 'v'.
// Output Format:
// Print number of Islands for each test case in new line.
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 1000
// 1 <= M <= min((N*(N-1))/2, 1000)
// 0 <= u[i] ,v[i] < N
// Output Return Format :
// The count the number of connected groups of islands
// Sample Input :
// 1
// 2 1
// 0 1
// Sample Output :
// 1 
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

void dfs(vvi &adj,int index,bool visited[]){

    visited[index]=true;
    for(auto v:adj[index]){
        if(visited[v]==false){
            dfs(adj,v,visited);
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;cin>>t;
while(t--){
    int n,m;cin>>n>>m;
    vvi adj(n);
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
       
    }
    int count=0;
    bool visited[n];
    memset(visited,false,sizeof(visited));

    for(int i=0;i<n;i++){
        
        if(!visited[i]){
            count++;    
 
            dfs(adj,i,visited);
        }
	}
    cout<<count<<nl;
}
}
