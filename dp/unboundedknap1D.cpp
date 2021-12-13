// unbounded knapack can be done using a 1D array only
// where the array is made in accordance with hte weight W 
// dp[i] stores thr max vallue which can be achieved using all item and i capacity of the kanpsack
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
    int n;cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];

    }
    int w;cin>>w;
    int dp[w+1];
    for(int i=0;i<=w;i++){
        dp[i]=0;
    }
    for(int i=0;i<=w;i++){
        for(int j=0;j<n;j++){
            if(wt[j]<=i){
                dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
            }
        }
    }
  
    cout<<dp[w]<<nl;
}