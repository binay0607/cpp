// here we will be given a array we have to return the number of subsets whose sum is equal to given value k
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


int subsetsum(int * arr,int n, int index, int k){
    if(index==n){
        if(k==0) return 1;
        else return 0;
    }

    int count=0;
    if(k-arr[index]>=0){
        count+=subsetsum(arr,n,index+1,k-arr[index]); //adding it once
    }

    count+=subsetsum(arr, n, index+1,k); // not adding it
    return count;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n,k;cin>>n>>k;
    int * arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<subsetsum(arr,n,0,k);
}