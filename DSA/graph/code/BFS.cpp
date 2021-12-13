// here we print the graph in level order that is we print the node and all the nodes connected with it and continue it.

// implementation->
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
#define fs(x)	 	cout<<fixed<<showpoint<<setprecision((x))
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ceel(a,b)   ((a+b-1)/b)
#define all(x)      (x).begin(),(x).end()
#define ll          long long
#define dp2(n,k) int** dp = new int*[n+1];for(int i=0;i<=n;i++){dp[i] = new int[k+1];}
#define M           1000000007
#define INF         1e18
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    int ** edges = new int *[n];
    for(int i=0;i<n;i++){
        edges[i]= new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    while(e--){
        int f,s; cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int startingvertex=0;
    bool check=true;
    int visited[n];
    for(int i=0;i<n;i++) visited[i]=0;
    while(check){  //for disconnected graph //a separate fun can also be made refer dfs code

        deque<int> q;
        q.push_back(startingvertex);
        visited[startingvertex]=1;
        while(!q.empty()){
            int i=q.front();
            q.pop_front();
            cout<<i<<" ";
            for(int j=0;j<n;j++){
                if(edges[i][j]==1 && visited[j]!=1 ){
                   
                    q.push_back(j);
                    visited[j]=1;
                
                }
            }
        }
      
        check=false;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                
                check=true;
                startingvertex=i;
                break;
            }
        }
    }
    cout<<nl;
   
    

}