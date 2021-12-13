// printing the shortest commom superseq 
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
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//int t;cin>>t;
//while(t--)
     string s1,s2;cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int **dp= new int*[n+1];
    rep(i,0,n+1){
        dp[i]=new int[m+1];
    }
    rep(i,0,n+1){
        dp[i][0]=0;
    }
    rep(i,0,m+1){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    // here when the char don't match we don't skip it we add the char we are gonna miss i.e. the opposite char we are going toward
    int i=n,j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;
            }else{
                ans+=s2[j-1];
                j--;
            }
        }
    }

    while(i>0){
        ans+=s1[i-1];
        
        i--;
    }
    while(j>0){
        ans+=s2[j-1];
       

        j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<nl;
}