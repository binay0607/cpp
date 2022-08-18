// given a array and k we have to find the element closest to k thus giving min diff
//just find ceil and floor and return whichever gives min diff

//we are gonna use a diff way
//when a element is not found after the loop low and high points to the neighbours of the element;
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
    rep(i,0,n){cin>>a[i];}
    int k;cin>>k;
    int i=0,j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==k){
            cout<<a[mid]<<nl;
            return 0;
        }else if(a[mid]<k){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    // cout<<i<<" "<<j<<nl;
    if(j<0){
        cout<<a[i]<<nl;return 0;
    }
    if(i>n-1){
        cout<<a[j]<<nl;return 0;
    }
    
    cout<<((a[i]-k<k-a[j])?a[i]:a[j])<<nl;


}