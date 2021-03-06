// first and last occurence of a number in a sorted array
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
int last_idx(vi a,int n,int target){
    int i=0,j=n-1;
    int idx=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==target){
            idx=mid;
            i=mid+1;
        }else if(a[mid]<target){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    return idx;
    
}
int first_idx(vi a,int n,int target){
    int i=0,j=n-1;
    int idx=-1;
    while(i<=j){
  
        int mid=i+(j-i)/2;
        if(a[mid]==target){
            idx=mid;
            j=mid-1;
        }else if(a[mid]<target){
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
    rep(i,0,n)cin>>a[i];
    int target;cin>>target;
    cout<<first_idx(a,n,target)<<nl;
    cout<<last_idx(a,n,target)<<nl;
  
}

// this problem can also be implemented to find number of occurence of element in the sorted array