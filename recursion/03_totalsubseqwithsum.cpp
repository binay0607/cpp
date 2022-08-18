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

int totalsubseqwithsum(int idx,vector<int> &a,int n, int sum,int currsum){
    if(idx==n){
        if(sum==currsum){
            return 1;
        }
       return 0; 
    }
    int first=0;
    if(a[idx]<=sum-currsum){
        currsum+=a[idx];
        first= totalsubseqwithsum(idx+1,a,n,sum,currsum);
        currsum-=a[idx];
    }
    
    int second= totalsubseqwithsum(idx+1,a,n,sum,currsum);
    return first+second;
    
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n;cin>>n;
    vector<int > a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum;cin>>sum;

    cout<<totalsubseqwithsum(0,a,n,sum,0)<<nl;
    
}