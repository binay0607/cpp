// Problem Statement : we have to find min number of coins to make the given sum
// this can also be done by greedy (done)
// we have to initialize the second row in accordence to a[0] value 
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
    int n=869167734;
    
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;cin>>k;
    int **dp= new int*[n+1];
    rep(i,0,n+1){
        dp[i]=new int[k+1];
    }
    rep(i,0,n+1){
        dp[i][0]=0;
    }
    rep(i,0,k+1){
        dp[0][i]=(INT_MAX)-1;
    }
    rep(i,1,k+1){
 
        if(i%a[0]==0){

            dp[1][i]=i/a[0];
        }else{

            dp[1][i]=(INT_MAX)-1;
        }
    }
  
    for(int i=2;i<=n;i++){
        
        for(int j=1;j<=k;j++){
            if(a[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-a[i-1]] , dp[i-1][j]);

            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=k;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<nl;
    // }
    cout<<dp[n][k]<<nl;
}