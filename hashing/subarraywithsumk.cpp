//count of subarray with sum k
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
    int n;cin>>n;
    vi a(n);
    int prefixsum[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        
        
    }
    unordered_map<int,int>mp;
    int target;cin>>target;
    int ans=0;
    // prefixsum[0]=a[0];
    int sum=0;
    for(int i=0;i<n;i++){
        // if(i>0){
        //     prefixsum[i]= prefixsum[i-1]+a[i];
        // }
        sum+=a[i];
        if(sum==target){
            ans++;
        }
        if(mp.find(sum-target)!=mp.end()){
            ans+=mp[sum-target];
        }
        mp[sum]++;
    }
    cout<<ans<<nl;
}