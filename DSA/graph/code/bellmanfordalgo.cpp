// here we implement is using bellmanford algo
// it work for neg edges also
// we check for all edges n-1 times to check the min ans i.e. we relax them

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

struct Edges{
	int s; //for source
	int d; //for destination
	int w; //for weight
};
void bellmanford(vector<Edges> a,int n,int e){
    int *dist=new int [n];
    rep(i,0,n)dist[i]=INT_MAX;
    dist[0]=0; //it will work for any other value also i.e. we can just intialize the source with zero and find the dist[destination] at last 
              //and thus getting shortest dist between given two vertices
    for(int i=0;i<n-1;i++){ //as we have to do this task n-1 times
        for(int j=0;j<e;j++){
            int src=a[j].s;
            int des=a[j].d;
            int edgew=a[j].w;
            if(dist[src]!=INT_MAX && dist[src]+edgew <dist[des]){
                dist[des]= dist[src]+edgew;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<nl;
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n,e;cin>>n>>e;
	vector<Edges> a(e);
	rep(i,0,e){
		cin>>a[i].s>>a[i].d>>a[i].w;
	}
    bellmanford(a,n,e);

}