//have to find two element with given sum
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
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;cin>>target;
    unordered_map<int ,int> mp;
        
    vector<int> ans;
    for(int i=0;i<a.size();i++){
        if(mp.find(target-a[i])!=mp.end()){ 
            ans.push_back(i);
            ans.push_back(mp[target-a[i]]);
               // return ans;
            //    break;
        }
        mp[a[i]]=i;
    }
    for(auto el:ans){
        cout<<el<<" ";
    }cout<<nl;

}