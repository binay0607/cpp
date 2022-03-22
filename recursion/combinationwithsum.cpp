//same as subseq sum just that we can take a element any number of times
//also we want to return the vector 
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
vector<vector<int>> g;
void printsubseqwithsum(int idx,vector<int> &a,vector<int>&ds,int n,int sum){
    if(idx==n){
        if(sum==0){
            g.push_back(ds);
        }
        return;
    }
    if(a[idx]<=sum){
        ds.push_back(a[idx]);
      
        printsubseqwithsum(idx,a,ds,n,sum-a[idx]);
        ds.pop_back();
    
    }
    
    printsubseqwithsum(idx+1,a,ds,n,sum);



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
    vector<int> ds;
    
    printsubseqwithsum(0,a,ds,n,sum);
    for(auto v:g){
        for(int el:v){
            cout<<el<<" ";
        }cout<<nl;
    }
}