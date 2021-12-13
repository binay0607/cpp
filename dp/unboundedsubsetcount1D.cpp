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
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ceel(a,b)   ((a+b-1)/b)
#define all(x)      (x).begin(),(x).end()
#define ll          long long
#define M           1000000007
#define INF         1e18
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//int t;cin>>t;
//while(t--)
    int n;cin>>n;
    int k;cin>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int dp[k+1];
    for(int i=0;i<=k;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=k;j++){
            dp[j]+=dp[j-a[i]];
         
        }
    }
    cout<<dp[k]<<nl;
}
// 6
// 2 3 5 6 8 10
// 10