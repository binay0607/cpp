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
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// int t;cin>>t;
// while(t--)
    int n;cin>>n;
    // int a[n];
    // rep(i,0,n){
    //     cin>>a[i];
    // }
    // sort(a,a+n);
    // // cout<<count_if(a,a+n,[](int x) {return x<3;})<<nl;
    // auto it1=upper_bound(a,a+n,2);
    // auto it2=lower_bound(a,a+n,2);

    // cout<<*it1<<" "<<*it2<<nl;
    // int i= lower_bound(a,a+n,4)-a;
    // cout<<i<<nl;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
  
    sort(v.begin(),v.end());
    auto it =upper_bound(v.begin(),v.end(),2);
    cout<<*upper_bound(v.begin(),v.end(),2)<<nl;
    cout<<*it<<nl;
    // don't want to use auto
    int itt=*upper_bound(v.begin(),v.end(),2);
    cout<<itt<<nl;
    int i=lower_bound(v.begin(),v.end(),4)-v.begin();
    cout<<i<<nl;
    int maxx= *max_element(v.begin(),v.end());
    cout<<maxx<<nl;
    int i=max_element(v.begin(),v.end())-v.begin();
    cout<<i<<nl;
}