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

    //dry run for understanding properly
    string s;cin>>s;
    vector<int> map(256,-1);
    int left=0,right=0;
    int n=s.size();
    int len=0;
    while(right<n){
        if(map[s[right]]!=-1){
            left=max(map[s[right]]+1,left);
        }
        map[s[right]]=right;
        len=max(len,right-left+1);
        right++;
    }
    cout<<len<<nl;
}