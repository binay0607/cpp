//here we have to print sum of all the subsets 
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
vector<vector<int>> ans;
void subsetsum(vector<int > a,int idx,int sum,vector<int> &ans,int n){
        if(idx==n ){
          ans.push_back(sum);  
          return;
        }
        subsetsum(a,idx+1,sum+a[idx],ans,n);
        subsetsum(a,idx+1,sum,ans,n);
        
    }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;cin>>n;
    vector<int > a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int > ans;
    subsetsum(a,0,0,ans,n);
    for(int el:ans){
        cout<<el<<" ";
    }cout<<nl;
}