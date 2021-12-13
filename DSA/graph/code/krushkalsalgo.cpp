// we have to find the min spanning tree
//key point is we sort the weights and keep choosing them as long as they don't form a loop
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
int find_my_parent(int * parent,int n){
	if(parent[n]==n){
		return n;
	}

	return find_my_parent(parent, parent[n]);
}
void update_parent(int * parent,int s,int d){// no need to implement it
	while(parent[d]!=d){
		d=parent[d];
	}
	parent[d]=parent[s];

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n,e;cin>>n>>e;
	vector<Edges> a(e);
	rep(i,0,e){
		cin>>a[i].s>>a[i].d>>a[i].w;
	}
	sort(a.begin(),a.end(),[&](Edges x,Edges y){
		return x.w<y.w;
	});
	int *parent= new int [n];
	rep(i,0,n) parent[i]=i;
;
	ll anssum=0;
	for(auto &el:a){
		// if(++count==n)break;
		int srcp=find_my_parent(parent,el.s);
		int desp=find_my_parent(parent,el.d);
		if(srcp!=desp){
			// update_parent(parent,el.s,el.d);
            parent[srcp]=desp;
			// cout<<el.s<<" "<<el.d<<" "<<el.w<<nl;
			anssum+=el.w;
		}
		
	}
	cout<<anssum<<nl;
}