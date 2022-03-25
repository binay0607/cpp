// to find largest common subsequence in given two strings
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
int lcsrec(string s1,string s2,int n,int m,int **dp){
    if(n==0 ||m==0){
        return 0;
    }
    if(dp[n][m]>-1){
        return dp[n][m];
    }
    int ans;
    if(s1[n-1]==s2[m-1]){
        ans=1+lcsrec(s1,s2,n-1,m-1,dp);
    }else{
        ans=max(lcsrec(s1,s2,n-1,m,dp),lcsrec(s1,s2,n,m-1,dp));
    }
    dp[n][m]=ans;
    return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    string s1,s2;cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int **dp= new int *[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int [m+1];
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    cout<<lcsrec(s1,s2,n,m,dp);
}