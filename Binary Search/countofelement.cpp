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
int lastocc(vi a,int k,int n){
    int i=0,j=n-1;
    int idx=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==k){
            idx=mid;
            i=mid+1;
        }else if(a[mid]<k){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    return idx;
}
int firstocc(vi a,int k,int n){
    int i=0,j=n-1;
    int idx=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==k){
            idx=mid;
            j=mid-1;

        }else if(a[mid]<k){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    return idx;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int k;cin>>k;
    sort(all(a));
    int firstindex=firstocc(a,k,n);
    int lastindex=lastocc(a,k,n);
    cout<<firstindex<<" "<<lastindex<<nl;
    cout<<lastindex-firstindex+1<<nl;

}