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
//int t;cin>>t;
//while(t--)
    int n,m;
	cin>>n>>m;
	int a[n+1][n+1];
	rep(i,0,n+1){
		rep(j,0,n+1){
			a[i][j]=0;
		}
	}

	while(m--){
		int x,y;cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}

	// rep(i,1,n+1){
	// 	rep(j,1,n+1){
	// 		cout<<a[i][j]<<" "; 
	// 	}
	// 	cout<<nl;
	// }
	
	vi count(n+1);
	rep(i,1,n+1){
		int sum=0;
		rep(j,1,n+1){
			sum+=a[i][j];
		}
		count[i]=sum;
	}
	// debug(count);
	bool check=false;
	for(int i=1;i<=n;i++){
		if(count[i]==1){
			check=true;
		}
	}
	int ans=0;
	while(check){
		ans++;
		vi to_change;
		for(int i=1;i<=n;i++){
			if(count[i]==1){
				for(int j=1;j<=n;j++){
					if(a[i][j]==1){
						a[j][i]==0;
						a[i][j]==0;
                        to_change.push_back(i);
						to_change.push_back(j);
						j=n+2;

					}
				}
			}
		}
		for(auto &el:to_change){
			count[el]--;
		}
		check=false;
		for(int i=1;i<=n;i++){
            // cout<<count[i]<<" ";
			if(count[i]==1){
				check=true;
			}
		}
        // cout<<nl;

	}
	
	cout<<ans<<nl;
}