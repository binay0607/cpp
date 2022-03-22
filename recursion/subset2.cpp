//here we need to print unique subsets
//we have a unique subseq using set but it give error somehow
//here we use logic like combsum2
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
void printsubseq(int idx,vector<int> &a,vector<int> &ds,int n){
 
    ans.push_back(ds);
    for(int i=idx;i<n;i++){
        if(i>idx && a[i]==a[i-1])continue;
        ds.push_back(a[i]);
        printsubseq(i+1,a,ds,n);
        ds.pop_back(); //to remove this pop_back part we can pass ds as value and not by ref
    }

    
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;cin>>n;
    vector<int > a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ds;
    sort(a.begin(),a.end());
    printsubseq(0,a,ds,n);
    for(auto v:ans){
        for(int el:v){
            cout<<el<<" ";
        }cout<<nl;
    }
}