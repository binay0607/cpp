// here a sorted array is rotated like :
// 1 2 4 5 6 becomes 4 5 6 1 2
// we have to find how many elements are rotated 
// this doesn't work if multiple occurrence are there

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
    rep(i,0,n)cin>>a[i];
    int i=0,j=n-1;
    if(a[i]<a[j]){
        cout<<0<<nl;
        return 0;
    }
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]<a[mid-1] && mid!=0){
            cout<<(n-mid)<<nl;
            break;
        }else if(a[mid]<a[0]){
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
}