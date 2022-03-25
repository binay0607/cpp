//we have to print if there is a subset with sum eqaul to given sum or not
//we are gonna use printtingsubsewith sum logic here
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

bool subsetsum(int idx,vector<int> &a,int n,int sum){
    if(idx==n){
        if(sum==0){
           return true;
        }
        return false;
    }
    bool first=false;
    if(a[idx]<=sum){
        first=subsetsum(idx+1,a,n,sum-a[idx]);
    }
    
    bool second=subsetsum(idx+1,a,n,sum);
     return first|| second;



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

    cout<<subsetsum(0,a,n,sum)<<nl;
}