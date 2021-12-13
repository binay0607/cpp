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
int get_minvertex(bool * visited, int *dist,int n){
    int minv=-1;
    rep(i,0,n){
        if(!visited[i] &&( minv==-1 || dist[i]<dist[minv])){
            minv=i;
        }
    }
    return minv;
}
void dijkstra(int ** edges,int n){
    bool * visited=new bool[n]();
    int *dist=new int [n];
    rep(i,0,n) dist[i]=1e9;
    dist[0]=0;
    for(int i=0;i<n-1;i++){ //we have to do it n-1 times
        int minvertex= get_minvertex(visited,dist,n);
 
        visited[minvertex]=true;
        for(int j=0;j<n;j++){
            if(!visited[j] && edges[minvertex][j]&& dist[minvertex]+edges[minvertex][j]<dist[j]){
                dist[j]=dist[minvertex]+edges[minvertex][j];   //if new dist i.e. from the least dist+edges value is less than prev value we update it 
            }
        }
    }


    rep(i,0,n){
        cout<<i<<" "<<dist[i]<<nl;
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n,e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
        edges[f][s] = weight;
		edges[s][f] = weight;
    }
    dijkstra(edges,n);


}