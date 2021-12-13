// this is a variation of subset problem with unbounded knapsack
// Problem Statement : we have to find the ways to make sum of coins equal to a given value form the given coin array
// supply of coin is unlimited so we can use them multiple times (unbounded kanpsack)
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
    int k;cin>>k;
    int **dp= new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[k+1];
    }
    for(int i=0;i<=k;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(a[i-1]<=j){
                dp[i][j]=(dp[i][j-a[i-1]] + dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k]<<nl;
}