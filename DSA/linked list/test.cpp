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
    int t;cin>>t;
    while(t--){
		int n;cin>>n;
		vi a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n==1 || n==2){
			cout<<0<<nl;
			continue;
		}
		sort(all(a));
		int diff=abs(a[1]-a[0]);
		int maxx=1;
		// cout<<maxx<<nl;
		int maxx_till_now=-1;
		
		for(int i=1;i+1<n;i++){
			if(abs(a[i+1]-a[i])==diff){
				maxx++;
			}else{
				diff=abs(a[i+1]-a[i]);
				maxx=1;
			}
			maxx_till_now=max(maxx,maxx_till_now);

		}
		cout<<n-maxx_till_now-1<<nl;
	}
}
