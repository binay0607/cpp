// mcm: matrix chain multiplication 
// given array is dimension of some matrix we have to find a way to get min number of multiplication
//  for a=2,3,4  the 2 martrix dimension are 2X3 and 3X4  (3-3 should be same for multiplication)
// its all about where we are putting the paranthesis (like associative law)
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
#define dp(n,k) int** dp = new int*[n+1];for(int i=0;i<=n;i++){dp[i] = new int[k+1];}
#define M           1000000007
#define INF         1e18
int dp[100][100];
int solvemcm(int a[], int i, int j,int **dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int minn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=solvemcm(a,i,k,dp)+solvemcm(a,k+1,j,dp)+(a[i-1]*a[k]*a[j]);
        minn=min(minn,temp);

    }
    dp[i][j]=minn;
    return minn;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
   
    int n;cin>>n;
    int a[n];
    rep(i,0,n){
        cin>>a[i];
    }
    dp(n,n);
    rep(i,0,n+1){
        rep(j,0,n+1){
            dp[i][j]=-1;
        }
    }
    // cout<<dp[1][2];
    cout<<solvemcm(a,1,n-1,dp)<<nl;
}