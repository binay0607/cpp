// to check how much val one can acquire given a particular wt
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
int knapsack(int wt[], int val[], int n,int w, int**dp){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
   
    if(wt[n-1]<=w){
        dp[n][w]=max(val[n-1]+knapsack(wt,val,n-1,w-wt[n-1],dp),knapsack(wt,val,n-1,w,dp));
    }else{
        dp[n][w]=knapsack(wt,val,n-1,w,dp);
    }
  
    return dp[n][w];
}
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
    int** dp = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new int[w + 1];
		for (int j = 0; j <= w; j++) {
			dp[i][j] = -1;
		}
	}
    cout<<knapsack(wt, val,n,w,dp );
    
}