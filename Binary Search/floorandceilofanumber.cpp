// in a sorted array if a number is present it is the floor and ceil of that number only
// but if its not present gretest number smaller than it is its floor
// similarly the smallest number greater than the number is its floor
// e.g:  in array 1 2 3 7 8 9 : floor of 5 is 4, and ceil of 5 is 7

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
int ceil(vi a,int n,int num){
    int i=0,j=n-1;
    int res=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==num){
            return num;
        }else if(a[mid]<num){
            i=mid+1;
        }else{
            res=a[mid];
            j=mid-1;
        }
    }
    return res;
}

int floor(vi a,int n, int num){
    int i=0,j=n-1;
    int res=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==num){
            return num;
        }else if(a[mid]<num){
            res=a[mid];
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    return res;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int num;cin>>num;
    cout<<floor(a,n,num)<<nl;
    cout<<ceil(a,n,num)<<nl;
}