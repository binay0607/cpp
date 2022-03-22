//we have to print all the permutation of an array(/string)
//in this optimised version we are not using both ds and map vector
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
void permutation(int idx,vector<int>a,int n){
    if(idx==n){
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<n;i++){
        swap(a[idx],a[i]);
        permutation(idx+1,a,n);
        swap(a[idx],a[i]);
          
        
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
      
    }
    permutation(0,a,n);
    for(auto v:ans){
        for(int el:v){
            cout<<el<<" ";
        }cout<<nl;
    }
    
}