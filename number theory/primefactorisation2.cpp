//in log(n) complexity using seive
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
int a[1000001];
void seive(){
    int n=1000001;
   for(int i=2;i*i<n;i++){
       if(a[i]==0){
           for(int j=i*i;j<n;j+=i){
               if(a[j]==0){
                   a[j]=i;
               }
           }
       }
   }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    seive();
    int n;cin>>n;
    while(n>1){
        // cout<<n<<" "<<a[n]<<nl;
        if(a[n]==0){
            a[n]=n;
        }
        cout<<a[n]<<" ";
        n/=a[n];
        // cout<<n<<" processed"<<nl;
    }cout<<nl;

}