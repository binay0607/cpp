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
    rep(i,0,n){
        cin>>a[i];
    }
    int k;cin>>k;
    int i=0,j=n-1;
    //first we will find the min element in the array
    //basically where the a[i]<a[i-1]
    int idx=-1;
    while(i<=j){
        int mid=i+(j-1)/2;
        if(a[mid]<a[mid-1] && mid!=0){
            idx=mid;
            break;
        }else if(a[mid]<a[0]){
            j=mid-1;
        }else{
            i=mid+1;
        }
      
    }
    cout<<idx<<nl;
    if(a[n-1]>=k){
        i=idx;j=n-1;
    }else{
        i=0,j=idx-1;
    }
    cout<<i<<" "<<j<<nl;
    //now implement binarysearch
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==k){
            cout<<mid<<nl;
            return 0;
        }else if(a[mid]<k){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
}