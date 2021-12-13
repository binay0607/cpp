// in this algo we can find the dist between any two vertices stored in a matrix
// we consider all the vertices and try to find path between two vertices using that vertex
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
void floydwarshall(int ** edges,int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(edges[i][k]!=INT_MAX && edges[k][j]!=INT_MAX && edges[i][k]+edges[k][j]<edges[i][j]){
                    edges[i][j]= edges[i][k]+edges[k][j];
                }
            }
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n,e;cin>>n>>e;
    int ** edges=new int *[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            if(i==j) edges[i][j]=0;
            else edges[i][j]=INT_MAX;
        }
    }
    while(e--){
        int f,s,w;cin>>f>>s>>w;
        edges[f][s]=min(edges[f][s],w); //the vertices may contain multiple edges
       	edges[s][f]=min(edges[s][f],w);
    }
    floydwarshall(edges,n);
    int src,des;cin>>src>>des;
    cout<<edges[src][des]<<nl;

}