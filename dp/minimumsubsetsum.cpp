// min diff that we can get after making two sub sets from the array
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
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=accumulate(a,a+n,0);

    int k;k=sum/2; //we can check for only half value of sum as other half will be in diff set
    bool **dp= new bool*[n+1];
    rep(i,0,n+1){
        dp[i]=new bool[k+1];
    }
    rep(i,0,k+1){
        dp[0][i]=false;
    }
    rep(i,0,n+1){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int ans;
    for(int i=k;i>=0;i--){
        if(dp[n][i]){
            ans=i;
            break;
        }
    }
    // cout<<ans<<nl;
    // if(sum%2){
    //     cout<<(sum-2*ans)<<nl;
    // }else{
        cout<<(sum-2*ans)<<nl;
    // }
}